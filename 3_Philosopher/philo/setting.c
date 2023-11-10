/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:30:43 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/25 16:34:59 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_input(int ac, char **av)
{
	int	i;
	int num;

	if (ac != 5 && ac != 6)
		return (input_error(1));
	i = 1;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		if (num <= 0)
			return (input_error(2));
		i++;
	}
	return (0);
}

int	set_info(t_info *info, int ac, char **av)
{
	info->number_of_philosophers = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->number_of_times_each_philosopher_must_eat = -1;
	if (ac == 6)
		info->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	info->time_meal_start = get_cur_time(0);
	info->is_dead = 0;
	return (0);
}

int	init_mutex(t_info *info)
{
	int	i;

	info->fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* (info->number_of_philosophers + 1));
	if (info->fork_mutex == NULL)
		return (-1);
	i = 1;
	while (i <= info->number_of_philosophers)
	{
		pthread_mutex_init(&(info->fork_mutex[i]), NULL);  // 1 ~ N번 포크 뮤텍스 초기화
		i++;
	}
	pthread_mutex_init(&(info->print_mutex), NULL);
	pthread_mutex_init(&(info->dead_mutex), NULL);
	pthread_mutex_init(&(info->time_mutex), NULL);
	return (0);
}

int	set_philo(t_info *info, t_philo **philo)
{
	int	i;

	(*philo) = (t_philo *)malloc(sizeof(t_philo) * (info->number_of_philosophers + 1));
	if ((*philo) == NULL)
		return (-1);
	i = 1;
	while (i <= info->number_of_philosophers)
	{
		(*philo)[i].id = i;
		(*philo)[i].cnt_eat = 0;
		(*philo)[i].right_fork = i;
		(*philo)[i].left_fork = (i + 1) % (info->number_of_philosophers);
		if ((*philo)[i].left_fork == 0)
			(*philo)[i].left_fork = info->number_of_philosophers;
		(*philo)[i].start_eat_time = 0;
		(*philo)[i].info = info;
		i++;
	}
	return (0);
}
