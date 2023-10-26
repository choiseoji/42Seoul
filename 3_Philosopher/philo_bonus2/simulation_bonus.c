/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:44:09 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/26 20:29:38 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void get_fork(t_info *info, t_philo *philo)
{
	int	i;
	
	i = 0;
	while (i < 2)
	{
		sem_wait(info->fork_semaphore);
		print_taken_a_fork(info, philo);
		i++;
	}
}

void	drop_fork(t_info* info)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		sem_post(info->fork_semaphore);
		i++;
	}
}

void	eating(t_info *info, t_philo *philo)
{
	// 포크 두개 가져오기
	sem_wait(info->fork_box_semaphore);
	get_fork(info, philo);
	// 밥 먹기
	print_is_eating(info, philo);
	while (philo->start_eat_time + info->time_to_eat > get_cur_time(info->time_meal_start))
	{
		check_is_dead(info, philo);
		usleep(100);
	}
	// 포크 내려놓기
	drop_fork(info);
	sem_post(info->fork_box_semaphore);
}

void	sleeping(t_info *info, t_philo *philo)
{
	print_is_sleeping(info, philo);
	while (philo->start_sleep_time + info->time_to_sleep > get_cur_time(info->time_meal_start))
	{
		check_is_dead(info, philo);
		usleep(100);
	}
}
