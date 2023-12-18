/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:43:03 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/18 17:04:59 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	// 좀비 무리 생성
	// 첫 좀비의 자리를 리턴함

	Zombie	*zombieArr = new Zombie[N];
	for(int i = 0; i < N; i++)
	{
		zombieArr[i].set_name(name);
	}
	return (zombieArr);
}
