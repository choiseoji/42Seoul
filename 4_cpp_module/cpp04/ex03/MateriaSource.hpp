/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:16:20 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/23 15:29:56 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "AMateria.hpp"

class MateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource &ms);
	MateriaSource& operator=(const MateriaSource &ms);
	~MateriaSource();

	void learnMateria(AMateria *);
	AMateria* createMateria(std::string const & type);
};

#endif
