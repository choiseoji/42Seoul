/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:27:38 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/27 15:32:03 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*meal_start(void *arg)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo *)arg;
	info = philo->info;
	if (philo->id % 2 == 0)
		usleep(1000);
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

int	start_simulation(t_info	*info, t_philo *philo)
{
	int	id;

	id = 1;
	while (id <= info->number_of_philosophers)
	{
		pthread_create(&philo[id].thread, NULL, meal_start, &philo[id]);
		id++;
	}
	set_monitoring(philo, info);
	wait_n_destroy(philo, info);
	return (0);
}

int main(int ac, char **av)
{
	t_info	info;
	t_philo	*philo;

	if (check_input(ac, av) < 0)
		return (0);
	if (set_info(&info, ac, av) < 0)
		return (0);
	if (init_mutex(&info) < 0)
		return (0);
	if (set_philo(&info, &philo) < 0)
		return (0);
	if (start_simulation(&info, philo) < 0)
		return (0);
	return (0);
}
