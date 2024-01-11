/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:14:08 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/11 21:01:10 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;

	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;

	std::cout << "String constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ct)
{
	this->name = ct.name;
	this->hitPoints = ct.hitPoints;
	this->energyPoints = ct.energyPoints;
	this->attackDamage = ct.attackDamage;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &ct)
{
	if (this != &ct)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->name = ct.name;
		this->hitPoints = ct.hitPoints;
		this->energyPoints = ct.energyPoints;
		this->attackDamage = ct.attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " has no hitPoints" << std::endl;
	else if (energyPoints == 0)
		std::cout << "ClapTrap " << name << " has no energyPoints" << std::endl;
	else
	{
		this->energyPoints -= 1;
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;

		std::cout << "=======" << name << "\'s " << "stat=======" << std::endl;
		std::cout << "hPoint: " << hitPoints << std::endl;
		std::cout << "ePoint: " << energyPoints << std::endl;
		std::cout << "aDamage: " << attackDamage << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->hitPoints -= amount;
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;

	std::cout << "=======" << name << "\'s " << "stat=======" << std::endl;
	std::cout << "hPoint: " << hitPoints << std::endl;
	std::cout << "ePoint: " << energyPoints << std::endl;
	std::cout << "aDamage: " << attackDamage << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " has no hitPoints" << std::endl;
	else if (energyPoints == 0)
		std::cout << "ClapTrap " << name << " has no energyPoints" << std::endl;
	else
	{
		this->hitPoints += amount;
		this->energyPoints -= 1;
		std::cout << "ClapTrap " << name << " gets " << amount << " points of hit point!" << std::endl;

		std::cout << "=======" << name << "\'s " << "stat=======" << std::endl;
		std::cout << "hPoint: " << hitPoints << std::endl;
		std::cout << "ePoint: " << energyPoints << std::endl;
		std::cout << "aDamage: " << attackDamage << std::endl;
	}
}
