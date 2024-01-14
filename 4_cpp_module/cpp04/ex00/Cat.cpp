/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:36:26 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/14 18:48:18 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "(Cat) Default constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "(Cat) Destructor called" << std::endl;
}

void Cat::makeSound(void)
{
	std::cout << "meow meow~ 😺" << std::endl;
}
