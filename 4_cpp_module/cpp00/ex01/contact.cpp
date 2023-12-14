/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:00:01 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/14 20:24:47 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}

Contact::Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
	first_name = fn;
	last_name = ln;
	nick_name = nn;
	phone_number = pn;
	darkest_secret = ds;
}

Contact::~Contact(void) {}

void	Contact::print_first_name(void)
{
	if (first_name.size() > 10)
	{
		std::cout << first_name.substr(0, 9) << "." << "|";
	}
	else
	{
		std::cout.width(10);
		std::cout << std::right << first_name;
		std::cout << "|";
	}
}

void	Contact::print_last_name(void)
{
	if (last_name.size() > 10)
	{
		std::cout << last_name.substr(0, 9) << "." << "|";
	}
	else
	{
		std::cout.width(10);
		std::cout << std::right << last_name;
		std::cout << "|";
	}
}

void	Contact::print_nick_name(void)
{
	if (nick_name.size() > 10)
	{
		std::cout << nick_name.substr(0, 9) << "." << "\n";
	}
	else
	{
		std::cout.width(10);
		std::cout << std::right << nick_name;
		std::cout << "\n";
	}
}
