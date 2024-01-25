/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:02:24 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/25 16:24:34 by seojchoi         ###   ########.fr       */
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

	virtual void makeSound() const;
	virtual std::string getType() const;
};

#endif
