/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_trgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:40:25 by seojchoi          #+#    #+#             */
/*   Updated: 2023/07/23 11:16:04 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_t(int trgb)
{
	return ((trgb & (0xFF << 24)) >> 24);
}

int	get_r(int trgb)
{
	return ((trgb & (0xFF << 16)) >> 16);
}

int	get_g(int trgb)
{
	return ((trgb & (0xFF << 8)) >> 8);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	make_color_int(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
