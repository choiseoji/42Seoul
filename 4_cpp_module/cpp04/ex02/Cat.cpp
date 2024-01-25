/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:36:26 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/25 16:30:11 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	this->catBrain = new Brain();

	std::cout << "(Cat) Default constructor called" << std::endl;
}

Cat::Cat(const Cat &c)
{
	this->type = c.type;
	this->catBrain = new Brain();
	for(int i = 0; i < 100; i++)
	{
		catBrain->setIdea(i, c.catBrain->getIdea(i));
	}

	std::cout << "(Cat) Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &c)
{
	if (this != &c)
	{
		this->type = c.type;
		if (catBrain)
			delete catBrain;
		this->catBrain = new Brain();
		for(int i = 0; i < 100; i++)
		{
			catBrain->setIdea(i, c.catBrain->getIdea(i));
		}

		std::cout << "(Cat) Copy Assignment operator called" << std::endl;
	}
	return (*this);
}

Cat::~Cat(void)
{
	delete catBrain;

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

Brain* Cat::getBrain(void)
{
	return (this->catBrain);
}

void Cat::setBrain(int idx, std::string idea)
{
	catBrain->setIdea(idx, idea);
}
