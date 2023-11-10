/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:34:23 by seojchoi          #+#    #+#             */
/*   Updated: 2023/07/22 12:18:39 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->ptr, vars->win);
		exit(0);
	}
	return (0);
}

int	exit_hook(void)
{
	exit(0);
}

void	set_mlx(t_vars *vars, t_image *image)
{
	vars->ptr = mlx_init();
	vars->win = mlx_new_window(vars->ptr, 1500, 1000, "FDF");
	image->img = mlx_new_image(vars->ptr, 1500, 1000);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	mlx_clear_window(vars->ptr, vars->win);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_info	info;
	t_map	**map;
	t_image	image;

	if (ac != 2)
		exit(1);
	invalid_file(av, &info);
	map = set_xyz_color(&info);
	rotate(&info, map);
	final_set_xy(&info, map);
	set_mlx(&vars, &image);
	draw_line(&info, &image, map);
	mlx_put_image_to_window(vars.ptr, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.ptr);
	return (0);
}
