/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:54:37 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/17 19:55:14 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->type = "WrongAnimal";

	std::cout << "(WrongAnimal) Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a)
{
	type = a.type;

	std::cout << "(WrongAnimal) Copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &a)
{
	if (this != &a)
	{
		type = a.type;

		std::cout << "(WrongAnimal) Copy Assignment operator called" << std::endl;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "(WrongAnimal) Destructor called" << std::endl;
}

void WrongAnimal::makeSound(void)
{
	std::cout << "WrongAnimal makes sound" << std::endl;
}

std::string WrongAnimal::getType(void)
{
	return (this->type);
}
