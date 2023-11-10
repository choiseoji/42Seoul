/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:58:16 by seojchoi          #+#    #+#             */
/*   Updated: 2023/06/05 15:04:56 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_2_elements(t_stack *stack)
{
	int	first_element;
	int	second_element;

	if (stack->size < 2)
		return ;
	first_element = stack->top->content;
	second_element = stack->top->next->content;
	stack->top->content = second_element;
	stack->top->next->content = first_element;
}

void	sa(t_stack **stack_a)
{
	swap_top_2_elements(*stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	swap_top_2_elements(*stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_top_2_elements(*stack_a);
	swap_top_2_elements(*stack_b);
	write(1, "ss\n", 3);
}
