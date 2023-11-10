/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:27:55 by seojchoi          #+#    #+#             */
/*   Updated: 2023/07/09 19:37:14 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		exit(1);
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
		exit(1);
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
