/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:57:10 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/19 19:21:12 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP
# include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon		&weapon;  // 레퍼런스 변수

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack();
};

#endif
