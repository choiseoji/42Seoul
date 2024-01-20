/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:49:03 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/19 20:53:44 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	this->dogBrain = new Brain();

	std::cout << "(Dog) Default constructor called" << std::endl;
}

Dog::Dog(const Dog &d)
{
	this->type = d.type;
	this->dogBrain = new Brain();
	for(int i = 0; i < 100; i++)
	{
		dogBrain->setIdea(i, d.dogBrain->getIdea(i));
	}

	std::cout << "(Dog) Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &d)
{
	if (this != &d)
	{
		this->type = d.type;
		this->dogBrain = new Brain();
		for(int i = 0; i < 100; i++)
		{
			dogBrain->setIdea(i, d.dogBrain->getIdea(i));
		}

		std::cout << "(Dog) Copy Assignment operator called" << std::endl;
	}
	return (*this);
}

Dog::~Dog(void)
{
	delete dogBrain;

	std::cout << "(Dog) Destructor called" << std::endl;
}

void Dog::makeSound(void)
{
	std::cout << "bow-wow!! 🐶" << std::endl;
}

std::string Dog::getType(void)
{
	return(this->type);
}

Brain* Dog::getBrain(void)
{
	return (this->dogBrain);
}

void Dog::setBrain(int idx, std::string idea)
{
	dogBrain->setIdea(idx, idea);
}

