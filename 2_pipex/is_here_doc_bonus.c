/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_here_doc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:19:47 by seojchoi          #+#    #+#             */
/*   Updated: 2023/08/31 16:00:17 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	is_limiter(char *str, char *limiter)
{
	int	i;

	i = 0;
	while (str[i] && limiter[i])
	{
		if (str[i] != limiter[i])
			return (0);
		i++;
	}
	if (!(str[i] == '\0' && limiter[i] == '\0'))
		return (0);
	free(str);
	return (1);
}

char	*make_tmp_file(void)
{
	int		i;
	char	*name;
	char	*new;
	char	*num;

	i = 1;
	name = "tmp";
	while (1)
	{
		num = ft_itoa(i);
		new = ft_strjoin(name, num);
		free(num);
		if (access(new, F_OK))
			break ;
		free(new);
		i++;
	}
	return (new);
}

int	here_doc(char **av, t_info *info)
{
	int		tmp_fd;
	char	*limiter;
	char	*str;

	info->tmpfile = make_tmp_file();
	tmp_fd = open(info->tmpfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (tmp_fd < 0)
		system_error();
	limiter = ft_strjoin(av[2], "\n");
	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		if (is_limiter(str, limiter))
			break ;
		write(tmp_fd, str, strlen(str));
		free(str);
	}
	free(limiter);
	close(tmp_fd);
	return (1);
}

int	is_here_doc(char *str)
{
	if (!ft_strncmp("here_doc", str, 9))
		return (1);
	return (0);
}
