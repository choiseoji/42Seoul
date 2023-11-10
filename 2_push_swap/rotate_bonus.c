/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:55:33 by seojchoi          #+#    #+#             */
/*   Updated: 2023/06/11 15:12:50 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rotate(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->top->next;
	stack->bottom->next = stack->top;
	stack->top->prev = stack->bottom;
	stack->bottom = stack->top;
	stack->top->next = NULL;
	stack->top = tmp;
	stack->top->prev = tmp;
}

void	ra(t_stack **stack_a)
{
	rotate(*stack_a);
}

void	rb(t_stack **stack_b)
{
	rotate(*stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(*stack_a);
	rotate(*stack_b);
}
