/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:09:53 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/20 19:46:37 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	this->type = "Animal";

	std::cout << "(Animal) Default constructor called" << std::endl;
}

Animal::Animal(const Animal &a)
{
	type = a.type;

	std::cout << "(Animal) Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &a)
{
	if (this != &a)
	{
		type = a.type;

		std::cout << "(Animal) Copy Assignment operator called" << std::endl;
	}
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "(Animal) Destructor called" << std::endl;
}
