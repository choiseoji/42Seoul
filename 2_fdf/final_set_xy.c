/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_set_xy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:54:49 by seojchoi          #+#    #+#             */
/*   Updated: 2023/07/23 12:59:49 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_start(int *x_start, int *y_start, t_info *info)
{
	*x_start = (1500 - (info->x_max * info->gap - info->x_min * info->gap)) / 2
		- info->x_min * info->gap;
	*y_start = (1000 - (info->y_max * info->gap - info->y_min * info->gap)) / 2
		- info->y_min * info->gap;
}

void	set_gap(t_info *info)
{
	int	tmp_gap;
	int	x_start;
	int	y_start;

	tmp_gap = 35;
	while (1)
	{
		set_start(&x_start, &y_start, info);
		if (x_start + info->x_max * tmp_gap < 1500
			&& y_start + info->y_max * tmp_gap < 1000
			&& x_start + info->x_min * tmp_gap > 0
			&& y_start + info->y_min * tmp_gap > 0)
			break ;
		tmp_gap--;
	}
	if (tmp_gap == 0)
		tmp_gap = 1;
	info->gap = tmp_gap;
}

void	xy_with_gap(t_info *info, t_map **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->y_size)
	{
		j = 0;
		while (j < info->x_size)
		{
			map[i][j].x *= info->gap;
			map[i][j].y *= info->gap;
			j++;
		}
		i++;
	}
}

void	final_set_xy(t_info *info, t_map **map)
{
	int	i;
	int	j;
	int	x_start;
	int	y_start;

	set_gap(info);
	xy_with_gap(info, map);
	set_start(&x_start, &y_start, info);
	i = 0;
	while (i < info->y_size)
	{
		j = 0;
		while (j < info->x_size)
		{
			map[i][j].x += x_start;
			map[i][j].y += y_start;
			j++;
		}
		i++;
	}
}
