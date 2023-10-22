/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:36:41 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/22 20:21:18 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	print_taken_a_fork(t_info *info, t_philo *philo)
{
	int	cur_time;
	
	check_is_dead(info, philo);
	sem_wait(info->print_semaphore);
	cur_time = get_cur_time(info->time_meal_start);
	printf("%d %d has taken a fork\n", cur_time, philo->id);
	sem_post(info->print_semaphore);
	return (0);
}

int	print_is_eating(t_info *info, t_philo *philo)
{
	int	cur_time;

	check_is_dead(info, philo);
	sem_wait(info->print_semaphore);
	cur_time = get_cur_time(info->time_meal_start);
	printf("%d %d is eating\n", cur_time, philo->id);
	sem_post(info->print_semaphore);
	sem_wait(info->time_semaphore);
	philo->start_eat_time = cur_time;
	sem_post(info->time_semaphore);
	return (0);
}

int	print_is_sleeping(t_info *info, t_philo *philo)
{
	int	cur_time;

	check_is_dead(info, philo);
	sem_wait(info->print_semaphore);
	cur_time = get_cur_time(info->time_meal_start);
	printf("%d %d is sleeping\n", cur_time, philo->id);
	sem_post(info->print_semaphore);
	sem_wait(info->time_semaphore);
	philo->start_sleep_time = cur_time;
	sem_post(info->time_semaphore);
	return (0);
}

int	print_is_thinking(t_info *info, t_philo *philo)
{
	int	cur_time;

	check_is_dead(info, philo);
	sem_wait(info->print_semaphore);
	cur_time = get_cur_time(info->time_meal_start);
	printf("%d %d is thinking\n", cur_time, philo->id);
	sem_post(info->print_semaphore);
	return (0);
}

int	print_is_died(t_info *info, t_philo *philo)
{
	int	cur_time;

	sem_wait(info->print_semaphore);
	cur_time = get_cur_time(info->time_meal_start);
	printf("%d %d is died\n", cur_time, philo->id);
	// sem_post(info->print_semaphore);
	return (0);
}
