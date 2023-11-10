/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:18:36 by seojchoi          #+#    #+#             */
/*   Updated: 2023/07/16 12:28:35 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	get_x(char *str)
{
	int	i;
	int	cnt;
	int	flag;

	i = 0;
	cnt = 0;
	flag = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		while (str[i] && str[i] != ' ')
		{
			flag = 1;
			i++;
		}
		if (flag == 1)
		{
			cnt++;
			flag = 0;
		}
	}
	return (cnt);
}

char	*strjoin_with_space(char const *s1, char const *s2)
{
	size_t	s1_s;
	size_t	s2_s;
	size_t	i;
	size_t	j;
	char	*new;

	s1_s = ft_strlen(s1);
	s2_s = ft_strlen(s2);
	new = (char *)malloc(s1_s + s2_s + 2);
	if (new == 0)
		exit(1);
	i = 0;
	while (i < s1_s)
	{
		new[i] = s1[i];
		i ++;
	}
	new[i++] = ' ';
	j = 0;
	while (j < s2_s)
		new[i++] = s2[j++];
	new[i] = '\0';
	free((void *)s1);
	free((void *)s2);
	return (new);
}

void	check_x_size(int fd, int *x, int *y, t_info *info)
{
	int		cur_x;
	char	*str;

	*y = 0;
	info->arr = ft_strdup("");
	str = get_next_line(fd);
	if (str == 0)
		invalid_file_error();
	str = ft_strtrim(str, "\n");
	*x = get_x(str);
	while (str != NULL)
	{
		(*y)++;
		str = ft_strtrim(str, "\n");
		cur_x = get_x(str);
		if (cur_x != *x)
			invalid_file_error();
		info->arr = strjoin_with_space(info->arr, str);
		str = get_next_line(fd);
	}
}

void	invalid_map(char *file, t_info	*info)
{
	int		x;
	int		y;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		invalid_file_error();
	}
	check_x_size(fd, &x, &y, info);
	info->x_size = x;
	info->y_size = y;
	close(fd);
}

void	invalid_file(char **av, t_info *info)
{
	int		i;
	char	*file_name;

	file_name = av[1];
	i = 0;
	while (file_name[i])
		i++;
	if (!(file_name[i - 1] == 'f' && file_name[i - 2] == 'd'
			&& file_name[i - 3] == 'f' && file_name[i - 4] == '.'))
		invalid_file_error();
	invalid_map(av[1], info);
}
