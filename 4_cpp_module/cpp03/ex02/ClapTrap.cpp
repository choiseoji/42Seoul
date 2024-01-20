/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:14:08 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/20 15:41:20 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->hitPoints = C_HP;
	this->energyPoints = C_EP;
	this->attackDamage = C_AD;

	std::cout << "(ClapTrap) Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = C_HP;
	this->energyPoints = C_EP;
	this->attackDamage = C_AD;

	std::cout << "(ClapTrap) String constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ct)
{
	this->name = ct.name;
	this->hitPoints = ct.hitPoints;
	this->energyPoints = ct.energyPoints;
	this->attackDamage = ct.attackDamage;
	std::cout << "(ClapTrap) Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &ct)
{
	if (this != &ct)
	{
		std::cout << "(ClapTrap) Copy assignment operator called" << std::endl;
		this->name = ct.name;
		this->hitPoints = ct.hitPoints;
		this->energyPoints = ct.energyPoints;
		this->attackDamage = ct.attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "(ClapTrap) Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (checkPoint())
	{
		this->energyPoints -= 1;
		std::cout << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		printStat();
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (checkPoint())
	{
		this->hitPoints -= amount;
		std::cout << name << " takes " << amount << " points of damage!" << std::endl;
		printStat();
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (checkPoint())
	{
		this->hitPoints += amount;
		this->energyPoints -= 1;
		std::cout << name << " gets " << amount << " points of hit point!" << std::endl;
		printStat();
	}
}

void ClapTrap::printStat(void)
{
	std::cout << "=======" << name << "\'s " << "stat=======" << std::endl;
	std::cout << "hPoint: " << hitPoints << std::endl;
	std::cout << "ePoint: " << energyPoints << std::endl;
	std::cout << "aDamage: " << attackDamage << std::endl;
}

bool ClapTrap::checkPoint(void)
{
	if (hitPoints == 0)
		std::cout << name << " has no hitPoints" << std::endl;
	else if (energyPoints == 0)
		std::cout << name << " has no energyPoints" << std::endl;
	else
		return (true);
	return (false);
}
