/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_xyz_color_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:23:48 by seojchoi          #+#    #+#             */
/*   Updated: 2023/07/16 12:22:25 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

char	check_ch(char *str, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == *str)
			return (i);
		i++;
	}
	return (-1);
}

int	calculate(char *str, char *base, int size, int idx)
{
	int	num;
	int	color;

	color = 0;
	while (str[idx])
	{
		num = check_ch(&str[idx], base);
		if (num != -1)
			color = color * size + num;
		else
			break ;
		idx++;
	}
	return (color);
}

int	set_color(char *str)
{
	int		idx;
	int		color;
	char	*base;

	if (!str)
		return (0xffffff);
	if (!(str[0] == '0' && str[1] == 'x'))
		invalid_file_error();
	base = "0123456789abcdef";
	idx = 2;
	while (str[idx])
	{
		if (!((str[idx] >= 'A' && str[idx] <= 'Z')
				|| (str[idx] >= 'a' && str[idx] <= 'z')
				|| (str[idx] >= '0' && str[idx] <= '9')))
			invalid_file_error();
		if (str[idx] >= 'A' && str[idx] <= 'Z')
			str[idx] = str[idx] + 32;
		idx++;
	}
	if (idx > 10)
		invalid_file_error();
	color = calculate(str, base, 16, 2);
	return (color);
}

void	set(int i, int j, t_info *info, t_map **map)
{
	int		arr_idx;
	char	**num_n_color;

	map[i][j].x = j;
	map[i][j].y = i;
	arr_idx = i * info->x_size + j;
	num_n_color = ft_split(info->split_arr[arr_idx], ',');
	map[i][j].z = ft_atoi(num_n_color[0]);
	map[i][j].color = set_color(num_n_color[1]);
	free_all(num_n_color);
}

t_map	**set_xyz_color(t_info *info)
{
	int		i;
	int		j;
	t_map	**map;

	map = (t_map **)malloc(sizeof(t_map *) * info->y_size);
	if (map == 0)
		exit(1);
	info->split_arr = ft_split(info->arr, ' ');
	i = 0;
	while (i < info->y_size)
	{
		map[i] = (t_map *)malloc(sizeof(t_map) * info->x_size);
		if (map[i] == 0)
			exit(1);
		j = 0;
		while (j < info->x_size)
		{
			set(i, j, info, map);
			j++;
		}
		i++;
	}
	free_all(info->split_arr);
	free(info->arr);
	return (map);
}
