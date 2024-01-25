/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:25:14 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/25 16:02:21 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	for(int i = 0; i < 100; i++)
	{
		ideas[i] = "";
	}
	std::cout << "(Brain) Default constructor called" << std::endl;
}

Brain::Brain(const Brain &b)
{
	for(int i = 0; i < 100; i++)
	{
		ideas[i] = b.ideas[i];
	}

	std::cout << "(Brain) Copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &b)
{
	if (this != &b)
	{
		for(int i = 0; i < 100; i++)
		{
			ideas[i] = b.ideas[i];
		}

		std::cout << "(Brain) Copy Assignment operator called" << std::endl;
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "(Brain) Destructor called" << std::endl;
}

const std::string& Brain::getIdea(int idx) const
{
	static const std::string error;

	if (idx >= 100 || idx < 0)
	{
		std::cout << "The index should have a value greater than 0 and less than 100" << std::endl;
		return (error);
	}
	return (this->ideas[idx]);
}

void	Brain::setIdea(int idx, std::string idea)
{
	if (idx >= 100 || idx < 0)
		std::cout << "The index should have a value greater than 0 and less than 100" << std::endl;
	ideas[idx] = idea;
}
