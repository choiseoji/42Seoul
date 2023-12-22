/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:18:36 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/20 17:17:34 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() { };

Harl::~Harl() { };

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
	std::cout << std::endl << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	std::cout << std::endl << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.";
	std::cout << std::endl << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl << std::endl;
}

void	Harl:: insignificant(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]";
	std::cout << std::endl;
}

int	getIdx(std::string level)
{
	std::string l[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for(int i = 0; i < 4; i++)
	{
		if (l[i] == level)
			return (i);
	}
	return (-1);
}

void	Harl::complain(std::string level)
{
	std::string l[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*FunctionPtr[5])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::insignificant};

	int idx = getIdx(level);
	switch(idx)
	{
		default: {
			(this->*FunctionPtr[4])();
			break ;
		}
		case 0:
			(this->*FunctionPtr[0])();
		case 1:
			(this->*FunctionPtr[1])();
		case 2:
			(this->*FunctionPtr[2])();
		case 3:
			(this->*FunctionPtr[3])();
	}
}
