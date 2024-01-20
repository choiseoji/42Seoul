/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:39:48 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/20 15:54:01 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	this->hitPoints = FragTrap::HP;
	this->energyPoints = ScavTrap::EP;
	this->attackDamage = FragTrap::AD;

	std::cout << "(DiamondTrap) Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name+"_clap_name")
{
	this->name = name;
	this->hitPoints = FragTrap::HP;
	this->energyPoints = ScavTrap::EP;
	this->attackDamage = FragTrap::AD;

	std::cout << "(DiamondTrap) String constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &dt)
{
	this->name = dt.name;
	this->hitPoints = dt.hitPoints;
	this->energyPoints = dt.energyPoints;
	this->attackDamage = dt.attackDamage;

	std::cout << "(DiamondTrap) Copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap &dt)
{
	if (this != &dt)
	{
		this->name = dt.name;
		this->hitPoints = dt.hitPoints;
		this->energyPoints = dt.energyPoints;
		this->attackDamage = dt.attackDamage;

		std::cout << "(DiamondTrap) Copy assignment operator called" << std::endl;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "(DiamondTrap) Destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	if (checkPoint())
	{
		std::cout << "ClapTrap's name: " << ClapTrap::name << std::endl;
		std::cout << "DiamondTrap's name: " << name << std::endl;
	}
}
