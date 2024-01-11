/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:19:31 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/11 21:22:40 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap A("A");

	A.attack("B");
	A.takeDamage(9);
	A.attack("C");
	A.beRepaired(3);

	std::cout << std::endl << std::endl << std::endl;

	ScavTrap C("C");

	C.attack("D");
	C.takeDamage(90);
	C.attack("E");
	C.beRepaired(30);

	return (0);
}
