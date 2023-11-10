/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 12:47:54 by seojchoi          #+#    #+#             */
/*   Updated: 2023/06/12 16:29:39 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "./get_next_line/get_next_line.h"

void	command_size_2(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (str[0] == 'p' && str[1] == 'a')
		pa(&stack_b, &stack_a);
	else if (str[0] == 'p' && str[1] == 'b')
		pb(&stack_a, &stack_b);
	else if (str[0] == 's' && str[1] == 'a')
		sa(&stack_a);
	else if (str[0] == 's' && str[1] == 'b')
		sb(&stack_b);
	else if (str[0] == 's' && str[1] == 's')
		ss(&stack_a, &stack_b);
	else if (str[0] == 'r' && str[1] == 'a')
		ra(&stack_a);
	else if (str[0] == 'r' && str[1] == 'b')
		rb(&stack_b);
	else if (str[0] == 'r' && str[1] == 'r')
		rr(&stack_a, &stack_b);
	else
	{
		write(1, "Error\n", 6);
		free(str);
		stack_free(stack_a);
		stack_free(stack_b);
		exit(1);
	}
}

void	command_size_3(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		rra(&stack_a);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		rrb(&stack_b);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		rrr(&stack_a, &stack_b);
	else
	{
		write(1, "Error\n", 6);
		free(str);
		stack_free(stack_a);
		stack_free(stack_b);
		exit(1);
	}
}

void	parsing(char *str, t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	size--;
	if (size < 2 || size > 3)
	{
		write(1, "Error\n", 6);
		free(str);
		stack_free(stack_a);
		stack_free(stack_b);
		exit(1);
	}
	if (size == 2)
		command_size_2(str, stack_a, stack_b);
	else if (size == 3)
		command_size_3(str, stack_a, stack_b);
	free(str);
}

int	is_sorted(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*str;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	check_input(av);
	stack_a = make_stack();
	stack_b = make_stack();
	fill_stack(ac, av, stack_a);
	fd = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		parsing(str, stack_a, stack_b);
		str = get_next_line(fd);
	}
	if (is_sorted(stack_a) && is_empty(stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	stack_free(stack_a);
	stack_free(stack_b);
	return (0);
}
