/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_set_xy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:54:49 by seojchoi          #+#    #+#             */
/*   Updated: 2023/07/23 13:00:53 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	set_gap(t_info *info, t_update *update)
{
	int	tmp_gap;
	int	start_x;
	int	start_y;

	tmp_gap = 35;
	while (1)
	{
		start_x = (1500 - ((info->x_size - 1) * tmp_gap)) / 2;
		start_y = (1000 - ((info->y_size - 1) * tmp_gap)) / 2;
		if (start_x + info->x_size * tmp_gap <= 1400
			&& start_y + info->y_size * tmp_gap <= 900
			&& start_x >= 100
			&& start_y >= 100)
			break ;
		tmp_gap--;
	}
	if (tmp_gap == 0)
		tmp_gap = 1;
	update->gap = tmp_gap;
}

void	xy_with_gap(t_info *info, t_update *update, t_map **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->y_size)
	{
		j = 0;
		while (j < info->x_size)
		{
			map[i][j].x *= update->gap;
			map[i][j].y *= update->gap;
			j++;
		}
		i++;
	}
}

void	final_set_xy(t_info *info, t_update *update, t_map **map)
{
	int	i;
	int	j;

	set_gap(info, update);
	xy_with_gap(info, update, map);
	update->x_start = (1500 - ((info->x_size - 1) * update->gap)) / 2;
	update->y_start = (1000 - ((info->y_size - 1) * update->gap)) / 2;
	i = 0;
	while (i < info->y_size)
	{
		j = 0;
		while (j < info->x_size)
		{
			map[i][j].x += update->x_start;
			map[i][j].y += update->y_start;
			j++;
		}
		i++;
	}
	update->x_ag = 0;
	update->y_ag = 0;
	update->z_ag = 0;
}
