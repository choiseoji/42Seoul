/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:43:03 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/24 14:04:53 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*zombieArr = new Zombie[N];
	for(int i = 0; i < N; i++)
	{
		zombieArr[i].setName(name);
	}
	return (zombieArr);
}
