/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:28:53 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/20 16:03:40 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	input_error(void)
{
	std::cout << "invalid input\n";
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		input_error();
		return (0);
	}

	Harl	h;
	h.complain(av[1]);

	return (0);
}
