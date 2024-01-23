/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:30:05 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/23 14:49:32 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cure_HPP
# define Cure_HPP
# include "AMateria.hpp"

class Cure : virtual public AMateria
{
public:
	Cure();
	Cure(const Cure &cure);
	Cure& operator=(const Cure &cure);
	~Cure();
};

#endif
