/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:56:14 by seojchoi          #+#    #+#             */
/*   Updated: 2023/06/11 19:17:20 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->bottom->prev;
	stack->bottom->next = stack->top;
	stack->top->prev = stack->bottom;
	stack->top = stack->bottom;
	tmp->next = NULL;
	stack->bottom = tmp;
	stack->top->prev = stack->top;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(*stack_a);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(*stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(*stack_a);
	reverse_rotate(*stack_b);
}
