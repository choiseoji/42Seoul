/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:43:40 by seojchoi          #+#    #+#             */
/*   Updated: 2023/03/25 13:59:49 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base(unsigned long long nbr, char *base)
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

int	ft_putp(unsigned long long ptr)
{
	int	len;

	if (write(1, "0x", 2) < 0)
		return (-1);
	len = 2;
	if (ptr == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		else
			return (3);
	}
	len += ft_putnbr_base(ptr, "0123456789abcdef");
	if (len == 1)
		return (-1);
	return (len);
}
