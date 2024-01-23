/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:46:14 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/23 13:40:16 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) { }

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria &a)
{
	this->type = a.type;
}

AMateria& AMateria::operator=(const AMateria &a)
{
	if (this != &a)
	{
		this->type = a.type;
	}
	return (*this);
}

AMateria::~AMateria() { }

std::string const & AMateria::getType(void) const
{
	return (this->type);
}

// void AMateria::use(ICharacter& target)
// {

// }
