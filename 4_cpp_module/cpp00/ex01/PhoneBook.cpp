/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:58:42 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/14 21:44:12 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	idx = 0;
	size = 0;
}

PhoneBook::~PhoneBook(void) {}

std::string	PhoneBook::get_info(std::string str)
{
	std::string info;

	std::cout << str << " > ";
	getline(std::cin, info);
	return (info);
}

void	PhoneBook::save_contact()
{
	std::cout << "\n====================add====================\n\n";
	Contact new_contact
		= Contact(get_info("first_name"), get_info("last_name"),\
			get_info("nick_name"), get_info("phone_number"), get_info("darkest_secret"));
	std::cout << "\n===================save====================\n\n";

	contact[idx % 8] = new_contact;
	idx++;
	if (size < 8)
		size++;
}

Contact	PhoneBook::get_contact(int idx)
{
	return (contact[idx]);
}

void	PhoneBook::print_contact_list(void)
{
	Contact	print_contact;

	std::cout << "\n==================search===================\n\n";
	std::cout << "     index|first name| last name| nick name\n";
	for(int i = 0; i < size; i++)
	{
		std::cout << "         " << i << "|";
		print_contact = get_contact(i);
		print_contact.print_first_name();
		print_contact.print_last_name();
		print_contact.print_nick_name();
	}
	std::cout << "\n===========================================\n\n";
}
