/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:19:40 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/23 14:49:38 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class Ice : virtual public AMateria
{
public:
	Ice();
	Ice(const Ice &ice);
	Ice& operator=(const Ice &ice);
	~Ice();
};

#endif
