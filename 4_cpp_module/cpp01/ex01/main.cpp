/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:40:05 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/18 17:24:46 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include "Zombie.hpp"

int main(void)
{
	int	N;
	std::string name;

	std::cin >> N;
	std::cin >> name;

	Zombie	*p;
	p =	zombieHorde(N, name);  // 좀비 무리의 첫 주소를 가져옴

	// 좀비가 한명씩 자기 소개..
	for(int i = 0; i < N; i++)
	{
		p[i].announce();
	}
	// p 배열 소멸자
	delete []p;
	return (0);
}
