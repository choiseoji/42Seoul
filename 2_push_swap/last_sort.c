/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:08:57 by seojchoi          #+#    #+#             */
/*   Updated: 2023/06/07 17:11:49 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_idx_0(t_stack *stack_a)
{
	int		idx;
	t_node	*node;

	idx = 0;
	node = stack_a->top;
	while (node)
	{
		if (node->content == 0)
			break ;
		node = node->next;
		idx++;
	}
	return (idx);
}

void	last_sort(t_stack *stack_a)
{
	int	idx;

	idx = search_idx_0(stack_a);
	if (idx >= (stack_a->size + 1) / 2)
		idx = (stack_a->size - idx) * -1;
	while (idx != 0)
	{
		if (idx < 0)
		{
			rra(&stack_a);
			idx++;
		}
		else
		{
			ra(&stack_a);
			idx--;
		}
	}
}
