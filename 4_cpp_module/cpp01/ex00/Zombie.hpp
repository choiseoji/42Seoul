/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:10:30 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/23 19:56:44 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
private:
	std::string name;

public:
	void announce(void);
	Zombie();
	Zombie(std::string name);
	~Zombie();
};

void 	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif
