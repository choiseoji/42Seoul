/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:27:17 by seojchoi          #+#    #+#             */
/*   Updated: 2023/07/16 12:22:30 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	invalid_file_error(void)
{
	write(2, "invalid file\n", 13);
	exit(1);
}

void	swap(double *a, double *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	while (src[i])
		i++;
	src_len = i;
	i = 0;
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (src_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && s1[end - 1] && ft_strchr(set, s1[end - 1]))
		end--;
	new = (char *)malloc(sizeof(char) * (end - start + 1));
	if (new == 0)
		exit(1);
	ft_strlcpy (new, &s1[start], end - start + 1);
	free((void *)s1);
	return (new);
}

int	ft_atoi(char *str)
{
	long long	i;
	long long	num;
	int			minus;

	i = 0;
	minus = 1;
	num = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num *= 10;
		num += (str[i] - '0');
		if (num * minus > 2147483647 || num * minus < -2147483648)
			invalid_file_error();
		i++;
	}
	if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		invalid_file_error();
	return (num * minus);
}
