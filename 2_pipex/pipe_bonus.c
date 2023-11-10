/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:14:48 by seojchoi          #+#    #+#             */
/*   Updated: 2023/08/31 15:46:31 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	backup(t_info *info)
{
	info->prev_fd[0] = info->cur_fd[0];
	info->prev_fd[1] = info->cur_fd[1];
}

void	do_cmd(char *cmd, char **ev, t_info *info)
{
	char	**p_cmd;

	p_cmd = ft_split(cmd, ' ');
	if (ft_strchr(p_cmd[0], '/'))
	{
		if (access(p_cmd[0], F_OK) == 0)
		{
			if (execve(p_cmd[0], p_cmd, ev) < 0)
				system_error();
		}
		else
			file_error(p_cmd[0]);
	}
	else if (check_is_access(&(info->envp), p_cmd[0]))
	{
		if (execve(info->envp.access_path, p_cmd, ev) < 0)
			system_error();
	}
	else
		command_error(cmd);
}

void	first_pipe(char *infile, char *first_cmd, t_info *info, char **ev)
{
	int		infile_fd;

	infile_fd = open(infile, O_RDONLY);
	if (infile_fd < 0)
		file_error(infile);
	if (dup2(infile_fd, 0) < 0)
		system_error();
	if (close(info->cur_fd[0]) < 0)
		system_error();
	if (dup2(info->cur_fd[1], 1) < 0)
		system_error();
	if (close(infile_fd) < 0)
		system_error();
	if (close(info->cur_fd[1]) < 0)
		system_error();
	unlink(info->tmpfile);
	do_cmd(first_cmd, ev, info);
}

void	mid_pipe(char *mid_cmd, t_info *info, char **ev)
{
	if (dup2(info->prev_fd[0], 0) < 0)
		system_error();
	if (close(info->prev_fd[1]) < 0)
		system_error();
	if (close(info->cur_fd[0]) < 0)
		system_error();
	if (dup2(info->cur_fd[1], 1) < 0)
		system_error();
	if (close(info->prev_fd[0]) < 0)
		system_error();
	if (close(info->cur_fd[1]) < 0)
		system_error();
	do_cmd(mid_cmd, ev, info);
}

void	last_pipe(char *outfile, char *last_cmd, t_info *info, char **ev)
{
	int		outfile_fd;

	if (info->flag == 1)
		outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd < 0)
		system_error();
	if (dup2(info->prev_fd[0], 0) < 0)
		system_error();
	if (close(info->prev_fd[1]) < 0)
		system_error();
	if (dup2(outfile_fd, 1) < 0)
		system_error();
	if (close(info->cur_fd[0]) < 0)
		system_error();
	if (close(info->cur_fd[1]) < 0)
		system_error();
	if (close(info->prev_fd[0]) < 0)
		system_error();
	if (close(outfile_fd) < 0)
		system_error();
	do_cmd(last_cmd, ev, info);
}
