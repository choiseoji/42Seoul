/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:43:03 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/23 20:00:45 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*zombieArr = new Zombie[N];
	for(int i = 0; i < N; i++)
	{
		zombieArr[i].set_name(name);
	}
	return (zombieArr);
}
