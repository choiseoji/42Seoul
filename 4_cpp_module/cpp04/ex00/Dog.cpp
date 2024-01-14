/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:49:03 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/14 18:50:58 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "(Dog) Default constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "(Dog) Destructor called" << std::endl;
}

void Dog::makeSound(void)
{
	std::cout << "bow-wow!! 🐶" << std::endl;
}
