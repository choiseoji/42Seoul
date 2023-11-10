/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:44:26 by seojchoi          #+#    #+#             */
/*   Updated: 2023/07/23 10:57:45 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color_trgb(t_color *color)
{
	int	s_color;
	int	e_color;

	s_color = color->s_color;
	e_color = color->e_color;
	color->start.t = get_t(s_color);
	color->start.r = get_r(s_color);
	color->start.g = get_g(s_color);
	color->start.b = get_b(s_color);
	color->end.t = get_t(e_color);
	color->end.r = get_r(e_color);
	color->end.g = get_g(e_color);
	color->end.b = get_b(e_color);
}

void	set_gradient(t_dda *set, double *dis)
{
	set->delta_x = set->e_x - set->s_x;
	set->delta_y = set->e_y - set->s_y;
	if (fabs(set->delta_x) >= fabs(set->delta_y))
		*dis = fabs(set->delta_x);
	else if (fabs(set->delta_x) < fabs(set->delta_y))
		*dis = fabs(set->delta_y);
	set->gradient_x = set->delta_x / *dis;
	set->gradient_y = set->delta_y / *dis;
}

void	set_cur_color(t_color *color, t_dda *set, double cur_x, double cur_y)
{
	double	ratio;

	ratio = 0;
	if (set->gradient_x == 1)
		ratio = (cur_x - set->s_x) / (set->e_x - set->s_x);
	else if (set->gradient_x == -1)
		ratio = (set->s_y - cur_x) / (set->s_y - set->e_y);
	else if (set->gradient_y == 1)
		ratio = (cur_y - set->s_y) / (set->e_y - set->s_y);
	else if (set->gradient_y == -1)
		ratio = (set->s_y - cur_y) / (set->s_y - set->e_y);
	color->cur.t = ratio * (color->end.t) + (1 - ratio) * (color->start.t);
	color->cur.r = ratio * (color->end.r) + (1 - ratio) * (color->start.r);
	color->cur.g = ratio * (color->end.g) + (1 - ratio) * (color->start.g);
	color->cur.b = ratio * (color->end.b) + (1 - ratio) * (color->start.b);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && x < 1500 && y > 0 && y < 1000)
	{
		dst = image->addr
			+ (y * image->line_length + x * (image->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	dda(t_dda *set, t_image	*image, t_color *color)
{
	int		i;
	int		cur_color;
	double	cur_x;
	double	cur_y;
	double	dis;

	set_color_trgb(color);
	set_gradient(set, &dis);
	cur_x = set->s_x;
	cur_y = set->s_y;
	i = 0;
	while (i < dis)
	{
		set_cur_color(color, set, cur_x, cur_y);
		cur_color = make_color_int(color->cur.t,
				color->cur.r, color->cur.g, color->cur.b);
		my_mlx_pixel_put(image, round(cur_x), round(cur_y), cur_color);
		cur_x += set->gradient_x;
		cur_y += set->gradient_y;
		i++;
	}
}
