/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:36:35 by seojchoi          #+#    #+#             */
/*   Updated: 2023/06/12 17:53:39 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	stack_free(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->top;
	while (node)
	{
		tmp = node;
		node = node -> next;
		free(tmp);
	}
	free(stack);
}

int	ft_atoi(char *str, t_stack *stack, long long num)
{
	long long	i;
	int			minus;

	i = 0;
	minus = 1;
	num = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		num *= 10;
		num += (str[i] - '0');
		if (num * minus > 2147483647 || num * minus < -2147483648)
		{
			stack_free(stack);
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return (num * minus);
}

void	is_duplicate(int num, t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	if (tmp != NULL)
	{
		while (tmp)
		{
			if (tmp->content == num)
			{
				stack_free(stack);
				write(1, "Error\n", 6);
				exit(1);
			}
			tmp = tmp->next;
		}
	}
}
