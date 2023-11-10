/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:32:57 by seojchoi          #+#    #+#             */
/*   Updated: 2023/03/24 15:30:35 by seojchoi         ###   ########.fr       */
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
		mod[i] = nbr % 16;
		nbr = nbr / 16;
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

int	ft_putnbr_hex(unsigned int nbr, char type)
{
	char	*s;
	int		len;

	len = 0;
	if (nbr == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		return (1);
	}
	if (type == 'x')
	{
		s = "0123456789abcdef";
		len += ft_putnbr_base(nbr, s);
	}
	else if (type == 'X')
	{
		s = "0123456789ABCDEF";
		len += ft_putnbr_base(nbr, s);
	}
	if (len < 0)
		return (-1);
	return (len);
}
