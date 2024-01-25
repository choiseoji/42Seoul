/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:36:26 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/25 15:18:54 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";

	std::cout << "(Cat) Default constructor called" << std::endl;
}

Cat::Cat(const Cat &c)
{
	this->type = c.type;

	std::cout << "(Cat) Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &c)
{
	if (this != &c)
	{
		this->type = c.type;

		std::cout << "(Cat) Copy Assignment operator called" << std::endl;
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "(Cat) Destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "meow meow~ 😺" << std::endl;
}

std::string Cat::getType(void) const
{
	return(this->type);
}
