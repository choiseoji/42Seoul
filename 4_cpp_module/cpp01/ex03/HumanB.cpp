/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:31:23 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/19 19:23:46 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB () { };

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::~HumanB () { };

void	HumanB::attack(void)
{
	std::cout << name << " ";
	std::cout <<  "attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)  // 래퍼런스로 가져와서
{
	this->weapon = &weapon;  // 가져온 변수의 주소를 포인터 변수로 받는다
}
