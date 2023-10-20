/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:07:18 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/20 14:59:37 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers_bonus.h>

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

int	check_is_dead(t_info *info, t_philo *philo)
{
	int	life;

	sem_wait(&(info->time_semaphore));
	life = philo->start_eat_time;
	sem_post(&(info->time_semaphore));
	if (life + info->time_to_die <= get_cur_time(info->time_meal_start))
	{
		// 죽은 경우
		exit(1);
	}
	return (0);
}

int	spend_time(t_info *info, t_philo *philo, int base_time, int passing_time)
{
	while (base_time + passing_time > get_cur_time(info->time_meal_start))
	{
		check_is_dead(info, philo);
		usleep(100);
	}
	return (0);
}
