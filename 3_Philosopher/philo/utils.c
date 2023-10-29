/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:34:29 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/10 18:04:50 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	input_error(int flag)
{
	if (flag == 1)
	{
		printf("you must have 4 or 5 inputs\n");
	}
	else if (flag == 2)
	{
		printf("input must be an integer greater than 0\n");
	}
	return (-1);
}

int	ft_atoi(char *str)
{
	long long	i;
	long long	num;

	i = 0;
	num = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num *= 10;
		num += (str[i] - '0');
		if (num > 2147483647 || num < -2147483648)
			return (-1);
		i++;
	}
	if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	return (num);
}

int	get_cur_time(int start_time)
{
	int				cur_time;
	struct timeval	time;

	gettimeofday(&time, NULL);
	cur_time = (time.tv_sec) * 1000 + (time.tv_usec) / 1000;
	return (cur_time - start_time);
}

int	check_is_dead(t_info *info)
{
	pthread_mutex_lock(&(info->dead_mutex));
	if (info->is_dead == 1)
	{
		pthread_mutex_unlock(&(info->dead_mutex));
		return (1);
	}
	pthread_mutex_unlock(&(info->dead_mutex));
	return (0);
}

int	spend_time(t_info *info, int base_time, int passing_time)
{
	while (base_time + passing_time > get_cur_time(info->time_meal_start))
	{
		if (check_is_dead(info))
			return (-1);
		usleep(100);
	}
	return (0);
}
