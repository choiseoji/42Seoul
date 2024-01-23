/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:56:27 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/20 19:50:57 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	Animal *animalArr[2];

	animalArr[0] = new Dog();
	animalArr[1] = new Cat();
	// delete called on non-final 'Animal' that has virtual functions but non-virtual destructor
	delete animalArr[0];
	delete animalArr[1];


	// 깊은 복사 확인
	Dog	original;
	Dog copy;

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
