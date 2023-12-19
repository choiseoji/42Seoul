/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:52:40 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/19 16:35:10 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() { };

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon() { };

const std::string&	Weapon::getType(void)
{
	return (type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}
