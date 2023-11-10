/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:09:15 by seojchoi          #+#    #+#             */
/*   Updated: 2023/06/08 18:11:16 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_same(t_stack *stack_a, t_stack *stack_b, int *a, int *b)
{
	while ((*a) != 0 && (*b) != 0 && (*a > 0 && *b > 0))
	{
		rr(&stack_a, &stack_b);
		*a -= 1;
		*b -= 1;
	}
	while ((*a) != 0 && (*b) != 0 && (*a < 0 && *b < 0))
	{
		rrr(&stack_a, &stack_b);
		*a += 1;
		*b += 1;
	}
}

void	rotate_stack_a(int idx, t_stack *stack_a)
{
	while (idx != 0)
	{
		if (idx > 0)
		{
			ra(&stack_a);
			idx--;
		}
		else
		{
			rra(&stack_a);
			idx++;
		}
	}
}

void	rotate_stack_b(int idx, t_stack *stack_b)
{
	while (idx != 0)
	{
		if (idx > 0)
		{
			rb(&stack_b);
			idx--;
		}
		else
		{
			rrb(&stack_b);
			idx++;
		}
	}
}

void	b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	idx_a;
	int	idx_b;

	while (stack_b->size != 0)
	{
		idx_a = 0;
		idx_b = 0;
		find_min_command(stack_a, stack_b, &idx_a, &idx_b);
		rotate_same(stack_a, stack_b, &idx_a, &idx_b);
		rotate_stack_a(idx_a, stack_a);
		rotate_stack_b(idx_b, stack_b);
		pa(&stack_b, &stack_a);
	}
}
