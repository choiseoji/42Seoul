/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:06:41 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/16 20:59:55 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &d);
	Dog&  operator=(const Dog &d);
	~Dog();

	void makeSound();
	std::string getType();
};

#endif
