/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:47:03 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/06 19:32:57 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	check_is_empty(int ac)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
}

int main(int ac, char **av)
{
	int	cnt;
	int	idx;

	check_is_empty(ac);
	cnt = 1;
	while (cnt < ac)
	{
		idx = 0;
		while (av[cnt][idx])
		{
			std::cout << char(toupper(av[cnt][idx]));
			idx++;
		}
		cnt++;
	}
	std::cout << "\n";
	return (0);
}
