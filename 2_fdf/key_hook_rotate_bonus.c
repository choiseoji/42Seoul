/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_rotate_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:33:54 by seojchoi          #+#    #+#             */
/*   Updated: 2023/07/23 12:54:45 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotate_up(t_vars *vars)
{
	vars->update.x_ag += 1 * (M_PI / 180);
	update(vars);
}

void	rotate_down(t_vars *vars)
{
	vars->update.x_ag -= 1 * (M_PI / 180);
	update(vars);
}

void	rotate_left(t_vars *vars)
{
	vars->update.y_ag -= 1 * (M_PI / 180);
	update(vars);
}

void	rotate_right(t_vars *vars)
{
	vars->update.y_ag += 1 * (M_PI / 180);
	update(vars);
}

void	change_angle(t_vars *vars, int keycode)
{
	if (keycode == ROTATE_UP)
		rotate_up(vars);
	else if (keycode == ROTATE_DOWN)
		rotate_down(vars);
	else if (keycode == ROTATE_LEFT)
		rotate_left(vars);
	else if (keycode == ROTATE_RIGHT)
		rotate_right(vars);
}
