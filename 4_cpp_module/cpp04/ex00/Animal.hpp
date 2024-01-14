/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:02:24 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/14 17:13:45 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAP_HPP
# include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	// 복사 생성자
	// 복사 대입 연산자
	~Animal();

	void makeSound();
};

#endif
