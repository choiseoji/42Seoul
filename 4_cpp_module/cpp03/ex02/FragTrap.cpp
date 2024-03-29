/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:00:38 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/20 15:47:18 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    this->hitPoints = F_HP;
	this->energyPoints = F_EP;
	this->attackDamage = F_AD;

    std::cout << "(FragTrap) Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    this->name = name;
    this->hitPoints = F_HP;
	this->energyPoints = F_EP;
	this->attackDamage = F_AD;

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
	if (checkPoint())
		std::cout << name << ": high five~" << std::endl;
}
