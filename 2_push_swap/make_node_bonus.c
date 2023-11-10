/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:50:06 by seojchoi          #+#    #+#             */
/*   Updated: 2023/06/12 10:48:15 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*make_stack(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == 0)
		exit(1);
	new->size = 0;
	new->top = NULL;
	new->bottom = NULL;
	return (new);
}

t_node	*make_node(int num)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == 0)
		exit(1);
	new -> content = num;
	new -> next = NULL;
	new -> prev = new;
	return (new);
}

void	make_top_node(int num, t_stack *stack)
{
	t_node	*new;

	new = make_node(num);
	stack->top = new;
	stack->bottom = new;
}

void	join_node(int num, t_stack *stack)
{
	t_node	*new;

	new = make_node(num);
	(stack->bottom)->next = new;
	new->prev = stack->bottom;
	stack->bottom = new;
}
