/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:45:57 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/20 15:45:06 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->hitPoints = S_HP;
	this->energyPoints = S_EP;
	this->attackDamage = S_AD;

	std::cout << "(ScavTrap) Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	this->hitPoints = S_HP;
	this->energyPoints = S_EP;
	this->attackDamage = S_AD;

	std::cout << "(ScavTrap) String constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &st)
{
	this->name = st.name;
	this->hitPoints = st.hitPoints;
	this->energyPoints = st.energyPoints;
	this->attackDamage = st.attackDamage;

	std::cout << "(ScavTrap) String constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap &st)
{
	if (this != &st)
	{
		std::cout << "(ScavTrap) Copy assignment operator called" << std::endl;
		this->name = st.name;
		this->hitPoints = st.hitPoints;
		this->energyPoints = st.energyPoints;
		this->attackDamage = st.attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "(ScavTrap) Destructor called" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (checkPoint())
		std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
		std::cout << "(ScavTrap) " << name << " has no hitPoints" << std::endl;
	else if (energyPoints == 0)
		std::cout << "(ScavTrap) " << name << " has no energyPoints" << std::endl;
	else
	{
		this->energyPoints -= 1;
		std::cout << "(ScavTrap) " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		printStat();
	}
}
