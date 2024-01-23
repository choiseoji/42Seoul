/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:07:22 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/23 15:14:13 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) { }

Character::Character(std::string name)
{
	this->name = name;
}

Character::Character(const Character &c)
{
	this->name = c.name;
}

Character& Character::operator=(const Character &c)
{
	if (this != &c)
	{
		this->name = c.name;
	}
	return (*this);
}

Character::~Character(void) { }

// 멤버 함수 구현
std::string const & Character::getName(void) const
{
	return (name);
}

void Character::equip(AMateria* m)
{

}

void Character::unequip(int idx)
{

}

void Character::use(int idx, ICharacter& target)
{

}
