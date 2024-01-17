/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:25:14 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/17 20:29:49 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "(Brain) Default constructor called" << std::endl;
}

Brain::Brain(const Brain &b)
{
	// ideas = b.ideas;

	std::cout << "(Brain) Copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &b)

Brain::~Brain(void)
{
	std::cout << "(Brain) Destructor called" << std::endl;
}
