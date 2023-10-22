/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:05:46 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/22 16:17:55 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	get_first_fork(t_info *info, t_philo *philo)
{
	sem_wait(info->fork_semaphore);  // 세마포어 하나 감소
	if (print_taken_a_fork(info, philo) < 0)
	{
		sem_post(info->fork_semaphore);  // 세마포어 하나 증가
		return (-1);
	}
	return (0);
}

int	get_second_fork(t_info *info, t_philo *philo)
{
	sem_wait(info->fork_semaphore);
	if (print_taken_a_fork(info, philo) < 0)
	{
		sem_post(info->fork_semaphore);
		sem_post(info->fork_semaphore);
		return (-1);
	}
	return (0);
}

int	drop_fork(t_info *info)
{
	sem_post(info->fork_semaphore);
	sem_post(info->fork_semaphore);
	return (0);
}

int	eating(t_info *info, t_philo *philo)
{
	if (get_first_fork(info, philo) < 0)
		return (-1);
	// if (info->number_of_philosophers == 1)
	// 	return (eat_alone(info));
	if (get_second_fork(info, philo) < 0)
		return (-1);
	if (print_is_eating(info, philo) < 0)
	{
		drop_fork(info);
		return (-1);
	}
	if (spend_time(info, philo, philo->start_eat_time, info->time_to_eat) < 0)
	{
		drop_fork(info);
		return (-1);
	}
	drop_fork(info);
	return (0);
}

int sleeping(t_info *info, t_philo *philo)
{
	if (print_is_sleeping(info, philo) < 0)
		return (-1);
	if (spend_time(info, philo, philo->start_sleep_time, info->time_to_sleep) < 0)
		return (-1);
	return (0);
}

int	thinking(t_info *info, t_philo *philo)
{
	if (print_is_thinking(info, philo) < 0)
		return (-1);
	return (0);
}
