/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:25:57 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/23 15:29:53 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) { }

MateriaSource::MateriaSource(const MateriaSource &ms)
{

}

MateriaSource& MateriaSource::operator=(const MateriaSource &ms)
{
	if (this != &ms)
	{

	}
	return (*this);
}

MateriaSource::~MateriaSource(void) { }

void MateriaSource::learnMateria(AMateria *)
{
	// Copies the Materia passed as a parameter and store it in memory so it can be cloned later
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	// Returns a new Materia
}
