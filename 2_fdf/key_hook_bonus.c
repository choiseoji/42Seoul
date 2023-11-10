/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:19:22 by seojchoi          #+#    #+#             */
/*   Updated: 2023/07/18 20:10:22 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	new_image(t_vars *vars)
{
	mlx_destroy_image(vars->ptr, vars->image.img);
	vars->image.img = mlx_new_image(vars->ptr, 1500, 1000);
	vars->image.addr = mlx_get_data_addr(vars->image.img,
			&vars->image.bits_per_pixel,
			&vars->image.line_length, &vars->image.endian);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->ptr, vars->win);
		exit(0);
	}
	new_image(vars);
	if (keycode == SCALE_UP || keycode == SCALE_DOWN)
		change_scale(vars, keycode);
	else if (keycode == ROTATE_DOWN || keycode == ROTATE_UP
		|| keycode == ROTATE_LEFT || keycode == ROTATE_RIGHT)
		change_angle(vars, keycode);
	else if (keycode == MOVE_DOWN || keycode == MOVE_UP
		|| keycode == MOVE_LEFT || keycode == MOVE_RIGHT)
		change_location(vars, keycode);
	mlx_put_image_to_window(vars->ptr, vars->win, vars->image.img, 0, 0);
	return (0);
}
