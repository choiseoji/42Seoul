/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:20:39 by seojchoi          #+#    #+#             */
/*   Updated: 2023/06/11 15:14:49 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_2_elements(t_stack *stack_a)
{
	sa(&stack_a);
}

void	sort_3_elements(t_stack *stack_a)
{
	while (!is_sorted(stack_a))
	{
		if (stack_a->top->content > stack_a->top->next->content)
		{
			if (stack_a->top->content > stack_a->bottom->content)
				ra(&stack_a);
			else
				sa(&stack_a);
		}
		else if (stack_a->top->next->content > stack_a->bottom->content)
			rra(&stack_a);
	}
}

void	sort_2_or_3(t_stack *stack_a)
{
	if (stack_a->size == 2)
	{
		sort_2_elements(stack_a);
		stack_free(stack_a);
		exit(0);
	}
	if (stack_a->size == 3)
	{
		sort_3_elements(stack_a);
		stack_free(stack_a);
		exit(0);
	}
}
