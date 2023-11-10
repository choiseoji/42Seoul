/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:10:13 by seojchoi          #+#    #+#             */
/*   Updated: 2023/06/07 13:50:33 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	all_bigger_than_pivot2(t_stack *stack_a, int pivot2)
{
	t_node	*node;

	node = stack_a->top;
	while (node)
	{
		if (node->content < pivot2)
			return (0);
		node = node->next;
	}
	return (1);
}

void	bigger_than_p2(t_stack *stack_a, int p2)
{
	if (stack_a->top->content > p2)
		ra(&stack_a);
}

void	between_p1_n_p2(t_stack *stack_a, t_stack *stack_b, int p1, int p2)
{
	if ((stack_a->top->content > p1) && stack_a->top->content <= p2)
		pb(&stack_a, &stack_b);
}

void	smaller_than_p1(t_stack *stack_a, t_stack *stack_b, int p1)
{
	if (stack_a->top->content <= p1)
	{
		pb(&stack_a, &stack_b);
		rb(&stack_b);
	}
}

void	a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	pivot1;
	int	pivot2;

	pivot1 = (stack_a->size) / 3;
	pivot2 = (stack_a->size) / 3 * 2;
	while (1)
	{
		if (stack_a->size == 3 || all_bigger_than_pivot2(stack_a, pivot2))
			break ;
		bigger_than_p2(stack_a, pivot2);
		between_p1_n_p2(stack_a, stack_b, pivot1, pivot2);
		smaller_than_p1(stack_a, stack_b, pivot1);
	}
	if (stack_a->size > 3)
	{
		while (stack_a->size != 3)
			pb(&stack_a, &stack_b);
	}
	sort_3_elements(stack_a);
}
