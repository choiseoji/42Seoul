/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:34:23 by seojchoi          #+#    #+#             */
/*   Updated: 2023/07/23 13:00:36 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2)
		exit(1);
	invalid_file(av, &(vars.info));
	vars.map = set_xyz_color(&(vars.info));
	vars.orig_map = set_orig_map(vars.info, vars.map);
	final_set_xy(&(vars.info), &(vars.update), vars.map);
	set_mlx(&vars, &(vars.image));
	draw_line(&(vars.info), &(vars.image), vars.map);
	mlx_put_image_to_window(vars.ptr, vars.win, vars.image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.ptr);
	return (0);
}
