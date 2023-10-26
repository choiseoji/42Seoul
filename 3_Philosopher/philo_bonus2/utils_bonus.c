/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:35:34 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/26 20:02:29 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	input_error(void)
{
	write(1, "input_error\n", 12);
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

void	check_is_dead(t_info *info, t_philo *philo)
{
	int	life;

	sem_wait(info->time_semaphore);
	life = philo->start_eat_time;
	sem_post(info->time_semaphore);
	if (life + info->time_to_die <= get_cur_time(info->time_meal_start))
	{
		print_is_died(info, philo);
		sem_post(info->end_semaphore);
		exit(0);
	}
	// 철학자가 죽었으면 죽었다고 출력하고 프로세스 exit
}

void	check_is_full(t_info *info)
{
	int	i;

	i = 1;
	while (i <= info->number_of_philosophers)
	{
		sem_wait(info->cnt_semaphore);
		i++;
	}
	sem_post(info->end_semaphore);
	exit(0);
}
