/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:00:48 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/20 15:48:24 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap f("FT");

	f.highFivesGuys();

	std::cout << std::endl << std::endl << std::endl;

	FragTrap ff("seo");
	ff.attack("D");
	ff.takeDamage(90);
	ff.attack("E");
	ff.takeDamage(10);
	ff.beRepaired(30);
	return (0);
}
