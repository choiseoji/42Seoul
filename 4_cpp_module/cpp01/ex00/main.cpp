/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:09:59 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/23 19:56:55 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::string name;
	std::cout << "name: ";
	getline(std::cin, name);

	Zombie *p;
	p = newZombie(name);
	p->announce();
	delete p;

	std::cout << "name: ";
	getline(std::cin, name);
	randomChump(name);
	return (0);
}
