/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_access_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:17:04 by seojchoi          #+#    #+#             */
/*   Updated: 2023/08/30 18:29:18 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	check_is_access(t_envp *envp, char *cmd)
{
	int		i;
	char	*tmp_path;

	i = 0;
	while (envp->path[i])
	{
		tmp_path = ft_strjoin(envp->path[i], "/");
		tmp_path = ft_strjoin(tmp_path, cmd);
		if (!access(tmp_path, F_OK))
		{
			envp->access_path = ft_strdup(tmp_path);
			return (1);
		}
		free(tmp_path);
		i++;
	}
	access(cmd, F_OK);
	return (0);
}

void	get_envp_path(char	**ev, t_envp *envp)
{
	int		i;
	char	*envp_path;

	i = 0;
	while (ev[i])
	{
		if (ft_strncmp("PATH=", ev[i], 5) == 0)
		{
			envp_path = ft_strtrim(ev[i], "PATH=");
			envp->path = ft_split(envp_path, ':');
			free(envp_path);
			break ;
		}
		i++;
	}
}
