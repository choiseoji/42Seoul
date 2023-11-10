/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:55:21 by seojchoi          #+#    #+#             */
/*   Updated: 2023/06/11 15:12:38 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
}

void	sb(t_stack **stack_b)
{
	swap_top_2_elements(*stack_b);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_top_2_elements(*stack_a);
	swap_top_2_elements(*stack_b);
}
