/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:22:59 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/10 18:15:08 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eat_alone(t_info *info)
{
	while (1)
	{
		if (check_is_dead(info))
		{
			pthread_mutex_unlock(&(info->fork_mutex[1]));
			return (-1);
		}
	}
	return (-1);
}

int	get_right_fork(t_info *info, int id, int right_fork)
{
	pthread_mutex_lock(&(info->fork_mutex[right_fork]));
	if (print_taken_a_fork(info, id) < 0)
	{
		pthread_mutex_unlock(&(info->fork_mutex[right_fork]));
		return (-1);
	}
	return (0);
}

int	get_left_fork(t_info *info, int id, int right_fork, int left_fork)
{
	pthread_mutex_lock(&(info->fork_mutex[left_fork]));
	if (print_taken_a_fork(info, id) < 0)
	{
		pthread_mutex_unlock(&(info->fork_mutex[right_fork]));
		pthread_mutex_unlock(&(info->fork_mutex[left_fork]));
		return (-1);
	}
	return (0);
}

int	drop_fork(t_info *info, int right_fork, int left_fork)
{
	pthread_mutex_unlock(&(info->fork_mutex[right_fork]));
	pthread_mutex_unlock(&(info->fork_mutex[left_fork]));
	return (0);
}

int eating(t_info *info, t_philo *philo)
{
	if (get_right_fork(info, philo->id, philo->right_fork) < 0)
		return (-1);
	if (info->number_of_philosophers == 1)
		return (eat_alone(info));
	if (get_left_fork(info, philo->id, philo->right_fork, philo->left_fork) < 0)
		return (-1);
	if (print_is_eating(info, philo) < 0)
	{
		drop_fork(info, philo->right_fork, philo->left_fork);
		return (-1);
	}
	if (spend_time(info, philo->start_eat_time, info->time_to_eat) < 0)
	{
		drop_fork(info, philo->right_fork, philo->left_fork);
		return (-1);
	}
	drop_fork(info, philo->right_fork, philo->left_fork);
	return (0);
}

int	sleeping(t_info *info, t_philo *philo)
{
	if (print_is_sleeping(info, philo) < 0)
		return (-1);
	if (spend_time(info, philo->start_sleep_time, info->time_to_sleep) < 0)
		return (-1);
	return (0);
}

int	thinking(t_info *info, t_philo *philo)
{
	if (print_is_thinking(info, philo) < 0)
		return (-1);
	return (0);
}
