/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:06:41 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/25 15:28:30 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *dogBrain;

public:
	Dog();
	Dog(const Dog &d);
	Dog&  operator=(const Dog &d);
	~Dog();

	void makeSound() const;
	std::string getType() const;

	Brain* getBrain();
	void setBrain(int idx, std::string idea);
};

#endif
