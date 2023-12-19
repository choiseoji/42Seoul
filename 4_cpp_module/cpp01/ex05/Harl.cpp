/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:18:36 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/19 21:12:38 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() { };

Harl::~Harl() { };

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
	std::cout << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	std::cout << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.";
	std::cout << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

void	Harl::complain(std::string level)
{
	typedef void	(Harl::*FunctionPtr)();

	FunctionPtr	functionPtr;
	switch(level[0])
	{
		case 'd': {
			functionPtr = &Harl::debug;
			break ;
		}
		case 'i': {
			functionPtr = &Harl::info;
			break ;
		}
		case 'w': {
			functionPtr = &Harl::warning;
			break ;
		}
		case 'e': {
			functionPtr = &Harl::error;
			break ;
		}
	}
	(this->*functionPtr)();
}
