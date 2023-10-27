/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:34:38 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/27 14:54:57 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	eat_alone(t_info *info, t_philo *philo)
{
	sem_wait(info->fork_semaphore);
	print_taken_a_fork(info, philo);
	while (1)
	{
		check_is_dead(info, philo);
	}
}

void	meal_start(t_info *info, t_philo *philo)
{
	if (info->number_of_philosophers == 1)
		eat_alone(info, philo);
	while (1)
	{
		eating(info, philo);
		sleeping(info, philo);
		print_is_thinking(info, philo);
		usleep(100);
	}
}

void	before_start(t_info *info)
{
	int	i;

	sem_wait(info->end_semaphore);
	i = 0;
	while (i < info->number_of_philosophers)
	{
		sem_wait(info->cnt_semaphore);
		i++;
	}
}

void	start_simulation(t_info *info, t_philo *philo)
{
	int		id;
	pid_t	cnt_pid;

	before_start(info);
	id = 1;
	while (id <= info->number_of_philosophers)
	{
		philo[id].pid = fork();
		if (philo[id].pid == 0)
		{
			meal_start(info, &philo[id]);
			break ;
		}
		id++;
	}
	// 모든 필로가 배부르게 먹었는지 확인
	if (info->number_of_times_each_philosopher_must_eat > 0)
	{
		cnt_pid = fork();
		if (cnt_pid == 0)
			check_is_full(info);
	}
	// 필로가 죽으면 모든 프로세스 종료시켜주기
	sem_wait(info->end_semaphore);
	id = 1;
	while (id <= info->number_of_philosophers)
	{
		kill(philo[id].pid, SIGINT);
		id++;
	}
}

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	*philo;

	if (check_input(ac, av) < 0)
		return (0);
	if (set_info(&info, ac, av) < 0)
		return (0);
	if (set_philo(&info, &philo) < 0)
		return (0);
	start_simulation(&info, philo);
	return (0);
}
