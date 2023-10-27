/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:35:52 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/27 15:23:56 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	check_input(int ac, char **av)
{
	int	i;
	int num;

	if (ac != 5 && ac != 6)
		return (input_error());
	i = 1;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		if (num <= 0)
			return (input_error());
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
	info->number_of_times_each_philosopher_must_eat = 0;
	if (ac == 6)
		info->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	info->time_meal_start = get_cur_time(0);
	// 세마포어 초기화
	sem_unlink((const char *)"fork");
	sem_unlink((const char *)"fork_box");
	sem_unlink((const char *)"print");
	sem_unlink((const char *)"end");
	sem_unlink((const char *)"cnt");
	info->fork_semaphore = sem_open("fork", O_CREAT, 0644, info->number_of_philosophers);
	info->fork_box_semaphore = sem_open("fork_box", O_CREAT, 0644, info->number_of_philosophers / 2);
	info->print_semaphore = sem_open("print", O_CREAT, 0644, 1);
	info->end_semaphore = sem_open("end", O_CREAT, 0644, 1);
	info->cnt_semaphore = sem_open("cnt", O_CREAT, 0644, info->number_of_philosophers);
	return (0);
}

int	set_philo(t_info *info, t_philo **philo)
{
	int	i;

	(*philo) = (t_philo *)malloc(sizeof(t_philo) * (info->number_of_philosophers + 1));
	if ((*philo) == 0)
		return (-1);
	i = 1;
	while (i <= info->number_of_philosophers)
	{
		(*philo)[i].id = i;
		(*philo)[i].cnt_eat = 0;
		(*philo)[i].start_eat_time = 0;
		(*philo)[i].info = info;
		i++;
	}
	return (0);
}

void	close_semaphore(t_info *info, t_philo *philo)
{
	sem_close(info->fork_semaphore);
	sem_close(info->fork_box_semaphore);
	sem_close(info->print_semaphore);
	sem_close(info->end_semaphore);
	sem_close(info->cnt_semaphore);
	free(philo);
}
