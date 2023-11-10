/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_move_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:56:55 by seojchoi          #+#    #+#             */
/*   Updated: 2023/07/23 13:24:18 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	move_left(t_vars *vars)
{
	vars->update.flag = 1;
	vars->update.x_start -= 2;
	update(vars);
}

void	move_right(t_vars *vars)
{
	vars->update.flag = 1;
	vars->update.x_start += 2;
	update(vars);
}

void	move_up(t_vars *vars)
{
	vars->update.flag = 1;
	vars->update.y_start -= 2;
	update(vars);
}

void	move_down(t_vars *vars)
{
	vars->update.flag = 1;
	vars->update.y_start += 2;
	update(vars);
}

void	change_location(t_vars *vars, int keycode)
{
	if (keycode == MOVE_LEFT)
		move_left(vars);
	else if (keycode == MOVE_RIGHT)
		move_right(vars);
	else if (keycode == MOVE_UP)
		move_up(vars);
	else if (keycode == MOVE_DOWN)
		move_down(vars);
}
