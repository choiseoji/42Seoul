/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:29:38 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/22 19:45:51 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H
# include <semaphore.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <signal.h>

// 정보를 담고 있을 info 구조체
typedef struct s_info
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	int	time_meal_start;
	
	// 세마포어
	sem_t	*fork_semaphore;
	sem_t	*time_semaphore;
	sem_t	*print_semaphore;
}	t_info;

// 철학자 1명의 정보를 담고 있을 philo 구조체
typedef struct s_philo
{
	int			id;
	int			cnt_eat;
	int			start_eat_time;
	int			start_sleep_time;
	pid_t		pid;
	t_info		*info;
}	t_philo;

// simulation_bonus
int	get_first_fork(t_info *info, t_philo *philo);
int	get_second_fork(t_info *info, t_philo *philo);
int	drop_fork(t_info *info);
int	eating(t_info *info, t_philo *philo);
int sleeping(t_info *info, t_philo *philo);
int	thinking(t_info *info, t_philo *philo);

// print_bonus
int	print_taken_a_fork(t_info *info, t_philo *philo);
int	print_is_eating(t_info *info, t_philo *philo);
int	print_is_sleeping(t_info *info, t_philo *philo);
int	print_is_thinking(t_info *info, t_philo *philo);
int	print_is_died(t_info *info, t_philo *philo);

// setting_bonus
int	check_input(int ac, char **av);
int	set_info(t_info *info, int ac, char **av);
int	set_philo(t_info *info, t_philo **philo);

// utils_bonus
int	input_error(void);
int	ft_atoi(char *str);
int	get_cur_time(int start_time);
int	check_is_dead(t_info *info, t_philo *philo);
int	spend_time(t_info *info, t_philo *philo, int base_time, int passing_time);

#endif
