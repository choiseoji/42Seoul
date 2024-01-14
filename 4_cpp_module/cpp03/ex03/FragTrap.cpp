/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:00:38 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/14 14:03:00 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;

    std::cout << "(FragTrap) Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    this->name = name;
    this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;

    std::cout << "(FragTrap) String constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ft)
{
	this->name = ft.name;
	this->hitPoints = ft.hitPoints;
	this->energyPoints = ft.energyPoints;
	this->attackDamage = ft.attackDamage;
	std::cout << "(FragTrap) Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap &ft)
{
	if (this != &ft)
	{
		std::cout << "(FragTrap) Copy assignment operator called" << std::endl;
		this->name = ft.name;
		this->hitPoints = ft.hitPoints;
		this->energyPoints = ft.energyPoints;
		this->attackDamage = ft.attackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "(FragTrap) Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << name << ": high five~" << std::endl;
}
