/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:40:05 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/23 20:45:53 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	inputNum(void)
{
	int	N;

	std::cout << "N : ";
	std::cin >> N;
	return (N);
}

std::string	inputName(void)
{
	std::string name;

	std::cout << "Name: ";
	std::cin >> name;
	return (name);
}

int main(void)
{
	int	N;
	std::string name;

	N = inputNum();
	name = inputName();

	Zombie	*p;
	p =	zombieHorde(N, name);

	for(int i = 0; i < N; i++)
	{
		p[i].announce();
	}
	delete []p;
	return (0);
}
