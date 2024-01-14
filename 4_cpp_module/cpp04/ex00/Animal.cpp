/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:09:53 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/14 18:35:46 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "(Animal) Default constructor called" << std::endl;
}

Animal::Animal(void)
{
	std::cout << "(Animal) Destructor called" << std::endl;
}

void Animal::makeSound(void)
{
	std::cout << "Animal makes sound" << std::endl;
}
