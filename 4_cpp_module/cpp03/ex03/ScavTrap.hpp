/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:37:09 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/14 16:54:20 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
	static const int HP = 100;
	static const int EP = 50;
	static const int AD = 20;

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &st);
	ScavTrap& operator = (const ScavTrap &st);
	~ScavTrap();

	void guardGate();
	void attack(const std::string& target);
};

#endif
