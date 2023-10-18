/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:25:55 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/18 20:05:26 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers_bonus.h>

int	meal_start(t_info *info, t_philo *philo)
{
	while (1)
	{
		if (eating(info, philo) < 0)
			return (0);
		if (sleeping(info, philo) < 0)
			return (0);
		if (thinking(info, philo) < 0)
			return (0);
	}
	return (0);
}

int	start_simulation(t_info *info, t_philo *philo)
{
	int	id;

	id = 1;
	while (id <= info->number_of_philosophers)
	{
		philo[id].pid = fork();
		if (philo[id].pid == 0)  // 자식 프로세스만 meal_start 함수로..
		{
			meal_start(info, philo);
			break ;
		}
		id++;
	}
	// 부모 프로세스에서 자식 프로세스 기다려주기
	id = 1;
	while (id <= info->number_of_philosophers)
	{
		waidpid(philo[id].pid, 0, 0);
		id++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	*philo;

	if (check_input(ac, av) < 0)
		return (0);
	if (set_info(&info, ac, av) < 0)
		return (0);
	if (set_philo(&info, &philo) < 0)
		return (0);
	if (start_simulation(&info, philo) < 0)
		return (0);
	return (0);
}
