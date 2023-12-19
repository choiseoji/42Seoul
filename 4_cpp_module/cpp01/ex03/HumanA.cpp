/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:59:09 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/19 19:21:09 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) { }

HumanA::~HumanA() { };

void	HumanA::attack(void)
{
	std::cout << name << " ";
	std::cout <<  "attacks with their " << weapon.getType() << std::endl;
}
