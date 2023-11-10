/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:53:40 by seojchoi          #+#    #+#             */
/*   Updated: 2023/06/12 17:52:47 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_blank(char *av)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (av[i])
	{
		if (av[i] != ' ')
			flag = 1;
		i++;
	}
	if (flag == 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

void	is_number(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		while (av[i] == ' ')
			i++;
		if (av[i] == '+' || av[i] == '-')
			i++;
		while (av[i] >= '0' && av[i] <= '9')
			i++;
		if (av[i] && av[i] != ' ' && (av[i] < '0' || av[i] > '9'))
		{
			write(1, "Error\n", 6);
			exit(1);
		}
	}
}

void	is_only_sign_or_more(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if ((av[i] == '+' || av[i] == '-')
			&& (av[i + 1] == '+' || av[i + 1] == '-'
				|| av[i + 1] == '\0' || av[i + 1] == ' '))
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

void	check_input(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		is_only_sign_or_more(av[i]);
		is_number(av[i]);
		is_blank(av[i]);
		i++;
	}
}
