/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:14:04 by seojchoi          #+#    #+#             */
/*   Updated: 2023/07/16 12:23:05 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	find;

	if (!s)
		return (0);
	find = (char)c;
	while (*s)
	{
		if (*s == find)
			return ((char *)s);
		s++;
	}
	if (*s == find)
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*new;

	size = 0;
	while (s1[size])
		size++;
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (new == 0)
		return (0);
	size = 0;
	while (s1[size])
	{
		new[size] = s1[size];
		size ++;
	}
	new[size] = '\0';
	return (new);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_s;
	size_t	s2_s;
	size_t	i;
	size_t	j;
	char	*new;

	s1_s = ft_strlen(s1);
	s2_s = ft_strlen(s2);
	new = (char *)malloc(s1_s + s2_s + 1);
	if (new == 0)
		return (0);
	i = 0;
	while (i < s1_s)
	{
		new[i] = s1[i];
		i ++;
	}
	j = 0;
	while (j < s2_s)
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}
