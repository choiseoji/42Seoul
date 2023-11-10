/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:43:08 by seojchoi          #+#    #+#             */
/*   Updated: 2023/06/11 19:58:18 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count(char const *s, char c)
{
	int	i;
	int	flag;
	int	word_cnt;

	i = 0;
	flag = 0;
	word_cnt = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			flag = 1;
			i++;
		}
		if (flag == 1)
		{
			word_cnt++;
			flag = 0;
		}
	}
	return (word_cnt);
}

char	*allocate_word(int idx, char const *s, char c)
{
	int		i;
	int		cnt;
	char	*malloc_temp;

	cnt = 0;
	while (s[idx + cnt] != c && s[idx + cnt] != 0)
		cnt++;
	malloc_temp = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!malloc_temp)
		return (0);
	i = 0;
	while (i < cnt)
	{
		malloc_temp[i] = s[idx + i];
		i++;
	}
	malloc_temp[i] = 0;
	return (malloc_temp);
}

char	**free_all(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		idx;
	int		word_cnt;
	char	**result;

	word_cnt = count(s, c);
	result = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!result)
		return (0);
	idx = 0;
	i = 0;
	while (s[idx] != 0 && i < word_cnt)
	{
		while (s[idx] == c && s[idx] != 0)
			idx++;
		result[i] = allocate_word(idx, s, c);
		if (result[i++] == 0)
			return (free_all(result));
		while (s[idx] != c && s[idx] != 0)
			idx++;
	}
	result[word_cnt] = 0;
	return (result);
}

void	fill_stack(int ac, char **av, t_stack *stack)
{
	int		i;
	int		j;
	int		num;
	char	**n;

	i = 0;
	while (++i < ac)
	{
		n = ft_split(av[i], ' ');
		j = 0;
		while (n[j])
		{
			num = ft_atoi(n[j], stack, 0);
			is_duplicate(num, stack);
			if (stack->top == NULL)
				make_top_node(num, stack);
			else
				join_node(num, stack);
			j++;
			stack->size++;
		}
		free_all(n);
	}
	is_one_para(stack);
	is_already_sorted(stack);
}
