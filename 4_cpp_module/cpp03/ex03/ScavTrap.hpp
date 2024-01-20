/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:37:09 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/20 15:54:58 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"
# define S_HP 100
# define S_EP 50
# define S_AD 20

class ScavTrap : virtual public ClapTrap
{
protected:
	static const int HP = S_HP;
	static const int EP = S_EP;
	static const int AD = S_AD;

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
