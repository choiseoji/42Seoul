/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:27:12 by seojchoi          #+#    #+#             */
/*   Updated: 2023/07/23 12:55:21 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	find_min_max(t_info *info, t_map **map, int i, int j)
{
	if (i == 0 && j == 0)
	{
		info->x_max = map[i][j].x;
		info->x_min = map[i][j].x;
		info->y_max = map[i][j].y;
		info->y_min = map[i][j].y;
	}
	if (info->x_max < map[i][j].x)
		info->x_max = map[i][j].x;
	if (info->x_min > map[i][j].x)
		info->x_min = map[i][j].x;
	if (info->y_max < map[i][j].y)
		info->y_max = map[i][j].y;
	if (info->y_min > map[i][j].y)
		info->y_min = map[i][j].y;
}

void	rotate_x(double *x, double *y, double *z, double ag)
{
	double		prev_x;
	double		prev_y;
	double		prev_z;

	prev_x = *x;
	prev_y = *y;
	prev_z = *z;
	*y = prev_y * cos(ag) - prev_z * sin(ag);
	*z = prev_y * sin(ag) + prev_z * cos(ag);
}

void	rotate_y(double *x, double *y, double *z, double ag)
{
	double		prev_x;
	double		prev_y;
	double		prev_z;

	prev_x = *x;
	prev_y = *y;
	prev_z = *z;
	*x = prev_z * sin(ag) + prev_x * cos(ag);
	*z = prev_z * cos(ag) - prev_x * sin(ag);
}

void	rotate_z(double *x, double *y, double *z, double ag)
{
	double		prev_x;
	double		prev_y;
	double		prev_z;

	prev_x = *x;
	prev_y = *y;
	prev_z = *z;
	*x = prev_x * cos(ag) - prev_y * sin(ag);
	*y = prev_x * sin(ag) + prev_y * cos(ag);
}

void	rotate(t_info *info, t_update *update, t_map **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->y_size)
	{
		j = 0;
		while (j < info->x_size)
		{
			rotate_x(&map[i][j].x, &map[i][j].y, &map[i][j].z, update->x_ag);
			rotate_y(&map[i][j].x, &map[i][j].y, &map[i][j].z, update->y_ag);
			rotate_z(&map[i][j].x, &map[i][j].y, &map[i][j].z, update->z_ag);
			find_min_max(info, map, i, j);
			j++;
		}
		i++;
	}
}
