/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonhan <jonhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:22:46 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/01 17:58:24 by jonhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	int_error(void)
{
	printf("Error\n");
	printf("input values must be in the integer(double) range\n");
	exit(1);
}

int	ft_atoi(const char *str)
{
	long long	i;
	int			minus;
	long long	num;

	i = 0;
	minus = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		minus *= -1;
		i++;
	}
	while ((str[i] >= 48 && str[i] <= 57) && str[i])
	{
		num *= 10;
		num += (str[i] - '0');
		if (num * minus > 2147483647 || num * minus < -2147483648)
			int_error();
		i++;
	}
	num *= minus;
	return (num);
}
