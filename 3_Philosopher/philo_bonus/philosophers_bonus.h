/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:29:38 by seojchoi          #+#    #+#             */
/*   Updated: 2023/10/18 20:07:59 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H
# include <semaphore.h>
# include <sys/time.h>
# define true 1
# define false 0

// 정보를 담고 있을 info 구조체
typedef struct s_info
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	int	time_meal_start;
	int	is_dead;
	
	sem_t	semaphore;  // 세마포어
	int		fork;  // 남은 포크의 개수
	
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

#endif
