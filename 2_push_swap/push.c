/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:13:15 by seojchoi          #+#    #+#             */
/*   Updated: 2023/06/07 16:58:50 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_dest(t_stack *dest, t_node *tmp)
{
	if (dest->size == 0)
	{
		tmp->next = NULL;
		dest->top = tmp;
		dest->bottom = tmp;
	}
	else
	{
		tmp->next = dest->top;
		dest->top->prev = tmp;
		dest->top = tmp;
	}
}

void	push_elements(t_stack *src, t_stack *dest)
{
	t_node	*tmp;

	if (src->size < 1)
		return ;
	tmp = src->top;
	if (src->size > 1)
	{
		src->top = src->top->next;
		src->top->prev = src->top;
	}
	set_dest(dest, tmp);
	if (src->size == 1)
	{
		src->top = NULL;
		src->bottom = NULL;
	}
	src->size -= 1;
	dest->size += 1;
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	push_elements(*stack_b, *stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push_elements(*stack_a, *stack_b);
	write(1, "pb\n", 3);
}
