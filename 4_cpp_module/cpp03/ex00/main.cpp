/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:19:31 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/11 17:25:30 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap A("A");

	A.attack("B");   // ePoint -1
	A.takeDamage(10);  // hitPoints - 10
	A.attack("C");  // hitPoints가 없으므로 공격 못 함
	A.beRepaired(3);  // hitPoints가 없으므로 공격 못 함

	std::cout << std::endl << std::endl << std::endl;
	ClapTrap B("B");

	B.beRepaired(5);  // hitPoints + 5, ePoint -1
	B.attack("A");  // ePoint -1
	B.attack("C");  // ePoint -1
	return (0);
}
