/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:54:28 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/27 15:00:38 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	print_taken_a_fork(t_info *info, t_philo *philo)
{
	int	cur_time;
	
	check_is_dead(info, philo);
	sem_wait(info->print_semaphore);
	cur_time = get_cur_time(info->time_meal_start);
	printf("%d %d has taken a fork\n", cur_time, philo->id);
	sem_post(info->print_semaphore);
}

void	print_is_eating(t_info *info, t_philo *philo)
{
	int	cur_time;

	check_is_dead(info, philo);
	sem_wait(info->print_semaphore);
	cur_time = get_cur_time(info->time_meal_start);
	printf("%d %d is eating\n", cur_time, philo->id);
	sem_post(info->print_semaphore);
	philo->start_eat_time = cur_time;
	// 먹은 cnt++ 해주기
	if (info->number_of_times_each_philosopher_must_eat > 0)
	{
		philo->cnt_eat++;
		if (philo->cnt_eat == info->number_of_times_each_philosopher_must_eat)  // cnt가 맞는 최초의 순간에만 sem_post
			sem_post(info->cnt_semaphore);
	}
}

void	print_is_sleeping(t_info *info, t_philo *philo)
{
	int	cur_time;

	check_is_dead(info, philo);
	sem_wait(info->print_semaphore);
	cur_time = get_cur_time(info->time_meal_start);
	printf("%d %d is sleeping\n", cur_time, philo->id);
	sem_post(info->print_semaphore);
	philo->start_sleep_time = cur_time;
}

void	print_is_thinking(t_info *info, t_philo *philo)
{
	int	cur_time;

	check_is_dead(info, philo);
	sem_wait(info->print_semaphore);
	cur_time = get_cur_time(info->time_meal_start);
	printf("%d %d is thinking\n", cur_time, philo->id);
	sem_post(info->print_semaphore);
}

void	print_is_died(t_info *info, t_philo *philo)
{
	int	cur_time;

	sem_wait(info->print_semaphore);
	cur_time = get_cur_time(info->time_meal_start);
	printf("%d %d is died\n", cur_time, philo->id);
	// sem_post(info->print_semaphore);
}
