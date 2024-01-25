/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:56:27 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/25 16:25:13 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	Animal *animalArr[4];

	for(int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			animalArr[i] = new Dog();
		else
			animalArr[i] = new Cat();
	}
	for(int i = 0; i < 4; i++)
	{
		delete animalArr[i];
	}


	// 깊은 복사 확인
	Dog	original;
	Dog copy;

	original.setBrain(-1, "dfdsf");
	original.setBrain(101, "dfdsf");
	// original -> idea에 초기값 설정
	for(int i = 0; i < 3; i++)
	{
		original.setBrain(i, "original");
	}

	copy = original;      // copy

	std::cout << std::endl << "=================" << std::endl;
	for(int i = 0; i < 3; i++)
	{
		std::cout << original.getBrain()->getIdea(i) << std::endl;
		std::cout << copy.getBrain()->getIdea(i) << std::endl;
		copy.setBrain(i, "copy");
	}
	std::cout << std::endl << "=================" << std::endl;
	for(int i = 0; i < 3; i++)
	{
		std::cout << original.getBrain()->getIdea(i) << std::endl;
		std::cout << copy.getBrain()->getIdea(i) << std::endl;
	}
	return (0);
}
