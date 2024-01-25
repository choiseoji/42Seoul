/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:49:03 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/25 15:19:03 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";

	std::cout << "(Dog) Default constructor called" << std::endl;
}

Dog::Dog(const Dog &d)
{
	this->type = d.type;

	std::cout << "(Dog) Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &d)
{
	if (this != &d)
	{
		this->type = d.type;

		std::cout << "(Dog) Copy Assignment operator called" << std::endl;
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "(Dog) Destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "bow-wow!! 🐶" << std::endl;
}

std::string Dog::getType(void) const
{
	return(this->type);
}
