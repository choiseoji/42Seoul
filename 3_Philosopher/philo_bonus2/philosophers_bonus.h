/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:29:38 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/26 20:28:47 by seojchoi         ###   ########.fr       */
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
	sem_t	*fork_box_semaphore;
	sem_t	*time_semaphore;
	sem_t	*print_semaphore;
	sem_t	*cnt_semaphore;
	sem_t	*end_semaphore;
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

// setting_bonus
int	check_input(int ac, char **av);
int	set_info(t_info *info, int ac, char **av);
int	set_philo(t_info *info, t_philo **philo);

// utils_bonus
int	input_error(void);
int	ft_atoi(char *str);
int	get_cur_time(int start_time);
void	check_is_dead(t_info *info, t_philo *philo);
void	check_is_full(t_info *info);

// simulation_bonus
void get_fork(t_info *info, t_philo *philo);
void	drop_fork(t_info* info);
void	eating(t_info *info, t_philo *philo);
void	sleeping(t_info *info, t_philo *philo);

// print_bonus
void	print_taken_a_fork(t_info *info, t_philo *philo);
void	print_is_eating(t_info *info, t_philo *philo);
void	print_is_sleeping(t_info *info, t_philo *philo);
void	print_is_thinking(t_info *info, t_philo *philo);
void	print_is_died(t_info *info, t_philo *philo);

#endif
