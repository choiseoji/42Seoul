/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:42:50 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/23 13:40:12 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>

class AMateria
{
protected:
	std::string type;

public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(const AMateria &a);
	AMateria& operator=(const AMateria &a);
	~AMateria();

	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	// virtual void use(ICharacter& target);
};

#endif
