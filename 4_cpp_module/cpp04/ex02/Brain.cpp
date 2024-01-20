/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:25:14 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/18 19:41:27 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
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
	return (this->ideas[idx]);
}

void	Brain::setIdea(int idx, std::string idea)
{
	ideas[idx] = idea;
}
