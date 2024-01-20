/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:02:24 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/20 19:41:51 by seojchoi         ###   ########.fr       */
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
	virtual ~Animal();

	virtual void makeSound() = 0;
	virtual std::string getType() = 0;
};

#endif
