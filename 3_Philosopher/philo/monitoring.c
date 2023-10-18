/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:05:37 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/10 20:11:07 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_must_eat_cnt(t_info *info, t_philo *philo, int id, int *cnt)
{
	int philo_eat_cnt;

	pthread_mutex_lock(&(info->time_mutex));
	philo_eat_cnt = philo[id].cnt_eat;
	pthread_mutex_unlock(&(info->time_mutex));
	if (info->number_of_times_each_philosopher_must_eat != -1 
	&& (philo_eat_cnt >= info->number_of_times_each_philosopher_must_eat))
		(*cnt)++;
	if ((*cnt) == info->number_of_philosophers)
	{
		pthread_mutex_lock(&info->dead_mutex);
		info->is_dead = 1;
		pthread_mutex_unlock(&info->dead_mutex);
		return (-1);
	}
	return (0);
}

int	check_life(t_info *info, t_philo *philo, int id)
{
	int	life;

	pthread_mutex_lock(&(info->time_mutex));
	life = philo[id].start_eat_time;
	pthread_mutex_unlock(&(info->time_mutex));
	if (life + info->time_to_die <= get_cur_time(info->time_meal_start))
	{
		pthread_mutex_lock(&(info->dead_mutex));
		info->is_dead = 1;
		print_is_died(info, philo[id].id);
		pthread_mutex_unlock(&(info->dead_mutex));
		return (-1);
	}
	return (0);
}

int	set_monitoring(t_philo *philo, t_info *info)
{
	int	id;
	int	cnt;

	while (info->number_of_philosophers)
	{
		id = 1;
		cnt = 0;
		while (id <= info->number_of_philosophers)
		{
			if (check_must_eat_cnt(info, philo, id, &cnt) < 0)
				return (0);
			if (check_life(info, philo, id) < 0)
				return (0);
			id++;
		}
	}
	return (0);
}

void	wait_n_destroy(t_philo *philo, t_info *info)
{
	int	id;

	id = 1;
	while (id <= info->number_of_philosophers)
	{
		pthread_join(philo[id].thread, NULL);
		id++;
	}
	id = 1;
	while (id <= info->number_of_philosophers)
	{
		pthread_mutex_destroy(&(info->fork_mutex[id]));
		id++;
	}
	pthread_mutex_destroy(&(info->print_mutex));
	pthread_mutex_destroy(&(info->dead_mutex));
	pthread_mutex_destroy(&(info->time_mutex));
}
