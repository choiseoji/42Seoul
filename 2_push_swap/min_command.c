/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:14:20 by seojchoi          #+#    #+#             */
/*   Updated: 2023/06/11 21:14:14 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_rotate(int idx, t_stack *stack)
{
	int	min_rotate;

	if (idx >= (stack->size + 1) / 2)
		min_rotate = (stack->size - idx) * -1;
	else
		min_rotate = idx;
	return (min_rotate);
}

int	idx_to_min_command(t_stack *stack_b, int b_idx)
{
	int	command;

	if (b_idx >= (stack_b->size + 1) / 2)
		command = (stack_b->size - b_idx);
	else
		command = b_idx;
	return (command);
}

int	find_min_command_in_a(t_stack *stack_a, int *a_idx, int content)
{
	t_node	*node_a;

	node_a = stack_a->top;
	while (node_a->next)
	{
		if ((node_a->content < node_a->next->content)
			&& node_a->content < content && node_a->next->content > content)
		{
			(*a_idx)++;
			break ;
		}
		if ((node_a->content > node_a->next->content)
			&& (node_a->content < content || node_a->next->content > content))
		{
			(*a_idx)++;
			break ;
		}
		(*a_idx)++;
		node_a = node_a->next;
	}
	if (node_a->content == stack_a->bottom->content)
		(*a_idx)++;
	return (idx_to_min_command(stack_a, *a_idx));
}

void	find_min_command(t_stack *stack_a, t_stack *stack_b, int *a, int *b)
{
	int		a_idx;
	int		b_idx;
	int		min_command;
	int		cur_command;
	t_node	*node_b;

	b_idx = 0;
	node_b = stack_b->top;
	while (b_idx < stack_b->size)
	{
		a_idx = 0;
		cur_command = find_min_command_in_a(stack_a, &a_idx, node_b->content);
		cur_command += idx_to_min_command(stack_b, b_idx);
		if (b_idx == 0 || min_command > cur_command)
		{
			min_command = cur_command;
			*a = find_min_rotate(a_idx, stack_a);
			*b = find_min_rotate(b_idx, stack_b);
		}
		node_b = node_b->next;
		b_idx++;
	}
}
