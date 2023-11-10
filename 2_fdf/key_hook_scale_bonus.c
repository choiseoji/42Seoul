/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_scale_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:04:11 by seojchoi          #+#    #+#             */
/*   Updated: 2023/07/23 13:20:42 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	scale_up(t_vars *vars)
{
	vars->update.gap += 1;
	update(vars);
}

void	scale_down(t_vars *vars)
{
	vars->update.gap -= 1;
	if (vars->update.gap == 0)
		vars->update.gap = 1;
	update(vars);
}

void	change_scale(t_vars *vars, int keycode)
{
	if (keycode == SCALE_UP)
		scale_up(vars);
	else if (keycode == SCALE_DOWN)
		scale_down(vars);
}
