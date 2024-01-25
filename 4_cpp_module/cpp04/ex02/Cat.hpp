/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:06:49 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/25 15:59:59 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *catBrain;

public:
	Cat();
	Cat(const Cat &c);
	Cat& operator=(const Cat &c);
	~Cat();

	void makeSound() const;
	std::string getType() const;

	Brain* getBrain();
	void setBrain(int idx, std::string idea);
};

#endif
