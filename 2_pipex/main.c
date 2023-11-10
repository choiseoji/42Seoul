/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:27:42 by seojchoi          #+#    #+#             */
/*   Updated: 2023/08/31 16:15:06 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**free_all(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}

void	close_n_wait(t_info info)
{
	free_all(info.path);
	close(info.fd[0]);
	close(info.fd[1]);
	waitpid(-1, 0, 0);
	waitpid(-1, 0, 0);
}

void	init_info(t_info *info)
{
	info->path = 0;
	info->access_path = 0;
	info->fd[0] = 0;
	info->fd[1] = 0;
}

void	get_envp_path(char	**ev, t_info *info)
{
	int		i;
	char	*envp_path;

	i = 0;
	while (ev[i])
	{
		if (ft_strncmp("PATH=", ev[i], 5) == 0)
		{
			envp_path = ft_strtrim(ev[i], "PATH=");
			info->path = ft_split(envp_path, ':');
			free(envp_path);
			break ;
		}
		i++;
	}
}

int	main(int ac, char **av, char **ev)
{
	t_info	info;
	int		pid;

	if (ac != 5)
		input_error();
	init_info(&info);
	get_envp_path(ev, &info);
	if (pipe(info.fd) < 0)
		system_error();
	pid = fork();
	if (pid < 0)
		system_error();
	if (pid == 0)
		first_cmd(av[1], av[2], &info, ev);
	pid = fork();
	if (pid < 0)
		system_error();
	else if (pid == 0)
		second_cmd(av[4], av[3], &info, ev);
	close_n_wait(info);
	return (0);
}
