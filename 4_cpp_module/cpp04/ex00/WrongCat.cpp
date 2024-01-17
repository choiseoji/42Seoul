/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:57:29 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/17 19:58:33 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";

	std::cout << "(WrongCat) Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &c)
{
	this->type = c.type;

	std::cout << "(WrongCat) Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &c)
{
	if (this != &c)
	{
		this->type = c.type;

		std::cout << "(WrongCat) Copy Assignment operator called" << std::endl;
	}
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "(WrongCat) Destructor called" << std::endl;
}

void WrongCat::makeSound(void)
{
	std::cout << "(wrong) meow meow~ 😺" << std::endl;
}

std::string WrongCat::getType(void)
{
	return(this->type);
}
