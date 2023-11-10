/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:28:31 by seojchoi          #+#    #+#             */
/*   Updated: 2023/07/23 12:46:19 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_next_x(t_dda *set, t_map **map, t_color *color)
{
	set->s_x = map[set->i][set->j].x;
	set->s_y = map[set->i][set->j].y;
	set->e_x = map[set->i][set->j + 1].x;
	set->e_y = map[set->i][set->j + 1].y;
	color->s_color = map[set->i][set->j].color;
	color->e_color = map[set->i][set->j + 1].color;
}

void	set_next_y(t_dda *set, t_map **map, t_color *color)
{
	set->s_x = map[set->i][set->j].x;
	set->s_y = map[set->i][set->j].y;
	set->e_x = map[set->i + 1][set->j].x;
	set->e_y = map[set->i + 1][set->j].y;
	color->s_color = map[set->i][set->j].color;
	color->e_color = map[set->i + 1][set->j].color;
}

void	draw_line( t_info *info, t_image *image, t_map **map)
{
	t_dda	set;
	t_color	color;

	set.i = -1;
	while (++set.i < info->y_size - 1)
	{
		set.j = -1;
		while (++set.j < info->x_size - 1)
		{
			set_next_x(&set, map, &color);
			dda(&set, image, &color);
			set_next_y(&set, map, &color);
			dda(&set, image, &color);
		}
		set_next_y(&set, map, &color);
		dda(&set, image, &color);
	}
	set.j = -1;
	while (++set.j < info->x_size - 1)
	{
		set_next_x(&set, map, &color);
		dda(&set, image, &color);
	}
}
