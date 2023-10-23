/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:25:55 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/23 15:54:23 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	meal_start(t_info *info, t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (eating(info, philo) < 0)
			return (0);
		if (sleeping(info, philo) < 0)
			return (0);
		if (thinking(info, philo) < 0)
			return (0);
	}
	return (0);
}

int	before_start(t_info *info)
{
	int	cnt;

	sem_wait(info->dead_semaphore);  // 일단 dead 세마포어 가져오기
	if (info->number_of_times_each_philosopher_must_eat > 0)
	{
		cnt = info->number_of_philosophers;
		while (cnt--)
		{
			sem_wait(info->cnt_semaphore);  // cnt 세마포어 다 가져오기
		}
	}
	return (0);
}

int	check_must_eat_cnt(t_info *info, t_philo *philo)
{
	int	cnt;
	int	id;

	cnt = 0;
	if (info->number_of_times_each_philosopher_must_eat == 0)
		return (0);
	while (cnt != info->number_of_philosophers)
	{
		sem_wait(info->cnt_semaphore);
		cnt++;
	}
	id = 1;
	while (id <= info->number_of_philosophers)
	{
		kill(philo[id].pid, SIGTERM);
		id++;
	}
	return (1);
}

int	simulation_stop(t_info *info, t_philo *philo)
{
	int	id;

	sem_wait(info->dead_semaphore);
	id = 1;
	while (id <= info->number_of_philosophers)
	{
		kill(philo[id].pid, SIGTERM);
		id++;
	}
	return (1);
}

int	start_simulation(t_info *info, t_philo *philo)
{
	int	id;

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
	if (check_must_eat_cnt(info, philo))
		return (0);
	if (simulation_stop(info, philo))
		return (0);
	return (0);
}

void	sem_close_n_unlink(t_info *info)
{
	sem_close(info->fork_semaphore);
	sem_close(info->time_semaphore);
	sem_close(info->print_semaphore);
	sem_close(info->dead_semaphore);
	sem_close(info->cnt_semaphore);
	sem_unlink((const char *)"fork");
	sem_unlink((const char *)"time");
	sem_unlink((const char *)"print");
	sem_unlink((const char *)"dead");
	sem_unlink((const char *)"cnt");
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
	if (start_simulation(&info, philo) < 0)
		return (0);
	sem_close_n_unlink(&info);
	return (0);
}
