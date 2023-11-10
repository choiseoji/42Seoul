/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:29:05 by seojchoi          #+#    #+#             */
/*   Updated: 2023/03/24 15:31:39 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base(unsigned int nbr, char *base)
{
	long long	i;
	long long	mod[100];
	int			len;

	i = 0;
	while (nbr >= 1)
	{
		mod[i] = nbr % 10;
		nbr = nbr / 10;
		i++;
	}
	len = 0;
	while (--i >= 0)
	{
		if (write(1, &base[mod[i]], 1) < 0)
			return (-1);
		len ++;
	}
	return (len);
}

int	ft_putnbr_u(unsigned int nbr)
{
	int		len;

	if (nbr == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		return (1);
	}
	len = ft_putnbr_base(nbr, "0123456789");
	if (len < 0)
		return (-1);
	return (len);
}
