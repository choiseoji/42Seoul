/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:39:43 by seojchoi          #+#    #+#             */
/*   Updated: 2023/08/31 16:11:37 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	make_pipe(t_info *info, char **av, char **ev)
{
	int		i;
	pid_t	pid;

	i = -1;
	while (++i < info->cmd_size)
	{
		if (i > 1)
			close_prev(info);
		backup(info);
		if (pipe(info->cur_fd) < 0)
			system_error();
		pid = fork();
		if (pid < 0)
			system_error();
		if (pid == 0)
		{
			if (i == 0)
				first_pipe(info->infile, av[info->cmd_idx], info, ev);
			else if (i != (info->cmd_size) - 1)
				mid_pipe(av[info->cmd_idx + i], info, ev);
			else
				last_pipe(info->outfile, av[info->cmd_idx + i], info, ev);
		}
	}
	close_n_wait(info);
}

void	init_info(t_info	*info)
{
	info->prev_fd[0] = 0;
	info->prev_fd[1] = 0;
	info->cur_fd[0] = 0;
	info->cur_fd[1] = 0;
	info->flag = 0;
	info->cmd_size = 0;
	info->cmd_idx = 0;
	info->infile = 0;
	info->outfile = 0;
	info->tmpfile = 0;
}

int	main(int ac, char **av, char **ev)
{
	t_info	info;

	init_info(&info);
	get_envp_path(ev, &(info.envp));
	if (ac > 5 && is_here_doc(av[1]))
	{
		here_doc(av, &info);
		info.flag = 1;
		info.cmd_size = (ac - 1) - 3;
		info.cmd_idx = 3;
		info.infile = info.tmpfile;
		info.outfile = av[ac - 1];
		make_pipe(&info, av, ev);
	}
	else if (ac > 4 && !is_here_doc(av[1]))
	{
		info.cmd_size = (ac - 1) - 2;
		info.cmd_idx = 2;
		info.infile = av[1];
		info.outfile = av[ac - 1];
		make_pipe(&info, av, ev);
	}
	else
		input_error();
	return (0);
}
