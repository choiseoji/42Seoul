/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:51:26 by seojchoi          #+#    #+#             */
/*   Updated: 2023/06/12 16:29:06 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	check_input(av);
	stack_a = make_stack();
	stack_b = make_stack();
	fill_stack(ac, av, stack_a);
	make_index(stack_a);
	sort_2_or_3(stack_a);
	a_to_b(stack_a, stack_b);
	b_to_a(stack_a, stack_b);
	last_sort(stack_a);
	stack_free(stack_a);
	stack_free(stack_b);
	return (0);
}
