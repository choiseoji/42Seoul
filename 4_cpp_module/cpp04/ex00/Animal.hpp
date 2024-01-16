/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:02:24 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/16 20:57:03 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(const Animal &a);
	Animal& operator=(const Animal &a);
	~Animal();

	virtual void makeSound();
	virtual std::string getType();
};

#endif
