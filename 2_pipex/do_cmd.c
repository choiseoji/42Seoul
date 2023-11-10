/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:16:48 by seojchoi          #+#    #+#             */
/*   Updated: 2023/08/31 16:01:04 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_is_access(t_info *info, char *cmd)
{
	int		i;
	char	*tmp_path;

	i = 0;
	while (info->path[i])
	{
		tmp_path = ft_strjoin(info->path[i], "/");
		tmp_path = ft_strjoin(tmp_path, cmd);
		if (access(tmp_path, F_OK) == 0)
		{
			info->access_path = ft_strdup(tmp_path);
			return (1);
		}
		free(tmp_path);
		i++;
	}
	return (0);
}

void	do_cmd(char *cmd, t_info *info, char **ev)
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
	else if (check_is_access(info, p_cmd[0]))
	{
		if (execve(info->access_path, p_cmd, ev) < 0)
			system_error();
	}
	else
		command_error(cmd);
}

void	first_cmd(char *infile, char *cmd1, t_info *info, char **ev)
{
	int		infile_fd;

	infile_fd = open(infile, O_RDONLY);
	if (infile_fd < 0)
		file_error(infile);
	if (dup2(infile_fd, 0) < 0)
		system_error();
	if (close(info->fd[0]) < 0)
		system_error();
	if (dup2(info->fd[1], 1) < 0)
		system_error();
	if (close(infile_fd) < 0)
		system_error();
	if (close(info->fd[1]) < 0)
		system_error();
	do_cmd(cmd1, info, ev);
}

void	second_cmd(char *outfile, char *cmd2, t_info *info, char **ev)
{
	int		outfile_fd;

	outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd < 0)
		system_error();
	if (dup2(info->fd[0], 0) < 0)
		system_error();
	if (close(info->fd[1]) < 0)
		system_error();
	if (dup2(outfile_fd, 1) < 0)
		system_error();
	if (close(info->fd[0]) < 0)
		system_error();
	if (close(outfile_fd) < 0)
		system_error();
	do_cmd(cmd2, info, ev);
}
