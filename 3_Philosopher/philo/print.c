/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:31:29 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/10 19:47:05 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	print_taken_a_fork(t_info *info, int id)
{
	int	cur_time;
	
	pthread_mutex_lock(&(info->print_mutex));
	if (check_is_dead(info))
	{
		pthread_mutex_unlock(&(info->print_mutex));
		return (-1);
	}
	cur_time = get_cur_time(info->time_meal_start);
	printf("%d %d has taken a fork\n", cur_time, id);
	pthread_mutex_unlock(&(info->print_mutex));
	return (0);
}

int	print_is_eating(t_info *info, t_philo *philo)
{
	int	cur_time;

	pthread_mutex_lock(&(info->print_mutex));
	if (check_is_dead(info))
	{
		pthread_mutex_unlock(&(info->print_mutex));
		return (-1);
	}
	cur_time = get_cur_time(info->time_meal_start);
	printf("%d %d is eating\n", cur_time, philo->id);
	pthread_mutex_unlock(&(info->print_mutex));
	// 마지막으로 먹은 시간과 먹는거 cnt 뮤텍스 락 걸고 갱신해주기
	pthread_mutex_lock(&(info->time_mutex));
	philo->start_eat_time = cur_time;
	philo->cnt_eat++;
	pthread_mutex_unlock(&(info->time_mutex));
	return (0);
}

int	print_is_sleeping(t_info *info, t_philo *philo)
{
	int	cur_time;

	pthread_mutex_lock(&(info->print_mutex));
	if (check_is_dead(info))
	{
		pthread_mutex_unlock(&(info->print_mutex));
		return (-1);
	}
	cur_time = get_cur_time(info->time_meal_start);
	printf("%d %d is sleeping\n", cur_time, philo->id);
	pthread_mutex_unlock(&(info->print_mutex));
	pthread_mutex_lock(&(info->time_mutex));
	philo->start_sleep_time = cur_time;
	pthread_mutex_unlock(&(info->time_mutex));
	return (0);
}

int	print_is_thinking(t_info *info, t_philo *philo)
{
	int	cur_time;

	pthread_mutex_lock(&(info->print_mutex));
	if (check_is_dead(info))
	{
		pthread_mutex_unlock(&(info->print_mutex));
		return (-1);
	}
	cur_time = get_cur_time(info->time_meal_start);
	printf("%d %d is thinking\n", cur_time, philo->id);
	pthread_mutex_unlock(&(info->print_mutex));
	return (0);
}

int	print_is_died(t_info *info, int id)
{
	int	cur_time;

	pthread_mutex_lock(&(info->print_mutex));
	cur_time = get_cur_time(info->time_meal_start);
	printf("%d %d is died\n", cur_time, id);
	pthread_mutex_unlock(&(info->print_mutex));
	return (0);
}
