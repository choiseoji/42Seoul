/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:10:49 by seojchoi          #+#    #+#             */
/*   Updated: 2023/07/25 19:02:32 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	cnt_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	command_error(char *cmd)
{
	int	size;

	write(2, "bash: ", 6);
	size = cnt_str(cmd);
	write(2, cmd, size);
	write(2, ": command not found\n", 20);
	exit(1);
}

void	file_error(char *file_name)
{
	write(2, "bash: ", 6);
	perror(file_name);
	exit(1);
}

void	input_error(void)
{
	write(2, "bash: input error\n", 18);
	exit(1);
}

void	system_error(void)
{
	char	*error;

	error = "bash";
	perror(error);
	exit(1);
}
