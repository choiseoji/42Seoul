/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_close_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:12:46 by seojchoi          #+#    #+#             */
/*   Updated: 2023/08/31 16:11:17 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	close_prev(t_info *info)
{
	close(info->prev_fd[0]);
	close(info->prev_fd[1]);
}

void	close_cur(t_info *info)
{
	close(info->cur_fd[0]);
	close(info->cur_fd[1]);
}

void	close_n_wait(t_info *info)
{
	int	i;

	free(info->tmpfile);
	free_all(info->envp.path);
	close_prev(info);
	close_cur(info);
	i = 0;
	while (i < info->cmd_size)
	{
		waitpid(-1, 0, 0);
		i++;
	}
}
