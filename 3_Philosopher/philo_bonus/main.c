/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:25:55 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/22 17:22:38 by seojchoi         ###   ########.fr       */
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

int	start_simulation(t_info *info, t_philo *philo)
{
	int	id;
	int	status;

	id = 1;
	while (id <= info->number_of_philosophers)
	{
		philo[id].pid = fork();
		if (philo[id].pid == 0)  // 자식 프로세스만 meal_start 함수로..
		{
			meal_start(info, &philo[id]);
			break ;
		}
		id++;
	}
	// 부모 프로세스에서 자식 프로세스 기다려주기
	id = 1;
	while (id <= info->number_of_philosophers)
	{
		waitpid(philo[id].pid, &status, 0);
		if (WIFEXITED(status) == 0)
			kill(philo[id].pid, SIGKILL);
		id++;
	}
	sem_close(info->fork_semaphore);
	sem_close(info->time_semaphore);
	sem_close(info->print_semaphore);
	return (0);
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
	return (0);
}
