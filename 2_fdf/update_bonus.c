/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:17:52 by seojchoi          #+#    #+#             */
/*   Updated: 2023/07/23 13:18:08 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	set_start(t_update *update, t_info *info)
{
	int	gap;

	gap = update->gap;
	update->x_start = (1500 - (info->x_max * gap - info->x_min * gap)) / 2
		- info->x_min * gap;
	update->y_start = (1000 - (info->y_max * gap - info->y_min * gap)) / 2
		- info->y_min * gap;
}

void	init_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->info.y_size)
	{
		j = 0;
		while (j < vars->info.x_size)
		{
			vars->map[i][j].x = vars->orig_map[i][j].x;
			vars->map[i][j].y = vars->orig_map[i][j].y;
			vars->map[i][j].z = vars->orig_map[i][j].z;
			vars->map[i][j].color = vars->orig_map[i][j].color;
			j++;
		}
		i++;
	}
}

t_map	**set_orig_map(t_info info, t_map **map)
{
	int		i;
	int		j;
	t_map	**orig_map;

	orig_map = (t_map **)malloc(sizeof(t_map *) * info.y_size);
	i = 0;
	while (i < info.y_size)
	{
		orig_map[i] = (t_map *)malloc(sizeof(t_map) * info.x_size);
		j = 0;
		while (j < info.x_size)
		{
			orig_map[i][j].x = map[i][j].x;
			orig_map[i][j].y = map[i][j].y;
			orig_map[i][j].z = map[i][j].z;
			orig_map[i][j].color = map[i][j].color;
			j++;
		}
		i++;
	}
	return (orig_map);
}

void	update(t_vars *vars)
{
	int	i;
	int	j;

	init_map(vars);
	rotate(&(vars->info), &(vars->update), vars->map);
	xy_with_gap(&(vars->info), &(vars->update), vars->map);
	if (!vars->update.flag)
		set_start(&(vars->update), &(vars->info));
	i = 0;
	while (i < vars->info.y_size)
	{
		j = 0;
		while (j < vars->info.x_size)
		{
			vars->map[i][j].x += vars->update.x_start;
			vars->map[i][j].y += vars->update.y_start;
			j++;
		}
		i++;
	}
	draw_line(&(vars->info), &(vars->image), vars->map);
}
