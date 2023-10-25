/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:20:30 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/25 16:34:52 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

// 정보를 담고 있을 info 구조체
typedef struct s_info
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	int	time_meal_start;   // 시뮬레이션이 시작하는 시간
	int	is_dead;  // 필로가 죽었다는 사실을 알려주기 위한 플래그
	
	// 각종 뮤텍스들
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	time_mutex;
}	t_info;

// 철학자 1명의 정보를 담고 있을 philo 구조체
typedef struct s_philo
{
	int			id;
	int			cnt_eat;
	int			right_fork;
	int			left_fork;
	int			start_eat_time;  // 마지막으로 먹은 시간 (수명 계산을 위해)
	int			start_sleep_time;
	t_info		*info;
	pthread_t	thread;
}	t_philo;

// setting.c
int		check_input(int ac, char **av);
int		set_info(t_info *info, int ac, char **av);
int		init_mutex(t_info *info);
int		set_philo(t_info *info, t_philo **philo);

// utils.c
int		input_error(void);
int		ft_atoi(char *str);
int		get_cur_time(int start_time);
int		check_is_dead(t_info *info);
int		spend_time(t_info *info, int base_time, int passing_time);

// simulation.c
int		get_right_fork(t_info *info, int id, int right_fork);
int		get_left_fork(t_info *info, int id, int right_fork, int left_fork);
int		eating(t_info *info, t_philo *philo);
int		sleeping(t_info *info, t_philo *philo);
int		thinking(t_info *info, t_philo *philo);

// monitoring.c
int		check_must_eat_cnt(t_info *info, t_philo *philo, int id, int *cnt);
int		check_life(t_info *info, t_philo *philo, int id);
int		set_monitoring(t_philo *philo, t_info *info);
void	wait_n_destroy(t_philo *philo, t_info *info);

// print.c
int		print_taken_a_fork(t_info *info, int id);
int		print_is_eating(t_info *info, t_philo *philo);
int		print_is_sleeping(t_info *info, t_philo *philo);
int		print_is_thinking(t_info *info, t_philo *philo);
int		print_is_died(t_info *info, int id);

#endif
