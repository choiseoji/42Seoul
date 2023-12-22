/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:26:49 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/22 20:27:36 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

void	inputError(void)
{
	std::cout << "input error\n";
}

int main(int ac, char **av)
{
	if (ac != 4)
		inputError();
	Replace r(av[1], av[2], av[3]);
	r.input();
	r.output();
	return (0);
}
