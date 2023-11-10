/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_idx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:58:24 by seojchoi          #+#    #+#             */
/*   Updated: 2023/06/12 11:04:00 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_arr(int *arr, int size)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	change_to_idx(int *arr, int size, t_stack *stack)
{
	t_node	*tmp;
	int		idx;

	tmp = stack->top;
	while (tmp)
	{
		idx = 0;
		while (idx < size)
		{
			if (arr[idx] == tmp->content)
			{
				tmp->content = idx;
				break ;
			}
			idx++;
		}
		tmp = tmp->next;
	}
}

void	make_index(t_stack *stack_a)
{
	int		size;
	int		*arr;
	int		i;
	t_node	*node;

	size = stack_a->size;
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == 0)
		exit(1);
	i = 0;
	node = stack_a->top;
	while (node)
	{
		arr[i] = node->content;
		node = node->next;
		i++;
	}
	sort_arr(arr, size);
	change_to_idx(arr, size, stack_a);
	free(arr);
}
