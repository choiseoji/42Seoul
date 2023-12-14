/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:08:58 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/12 15:35:23 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"
#include "contact.hpp"

void	print_format(void)
{
	std::cout << "\n==================search===================\n\n";
	std::cout.width(10);
	std::cout << std::right << "index";
	std::cout << "|";
	std::cout.width(10);
	std::cout << std::right << "first name";
	std::cout << "|";
	std::cout.width(10);
	std::cout << std::right << "last name";
	std::cout << "|";
	std::cout.width(10);
	std::cout << std::right << "nick name";
	std::cout << "\n";
}

std::string	get_info(std::string str)
{
	std::string info;

	std::cout << str << " > ";
	getline(std::cin, info);
	return (info);
}

int main(void)
{
	std::string		cmd;
	PhoneBook 		phone_book;

	while (1)
	{
		getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			std::cout << "\n====================add====================\n\n";

			Contact new_contact 
				= Contact(get_info("first_name"), get_info("last_name"),\
				 get_info("nick_name"), get_info("phone_number"), get_info("darkest_secret"));

			std::cout << "\n===================save====================\n\n";
			phone_book.Add(new_contact);
		}
		else if (cmd == "SEARCH")
		{
			print_format();
			for(int i = 0; i < 8; i++)
			{
				std::cout.width(10);
				std::cout << std::right << i + 1;
				std::cout << "|";
				if (phone_book.get_contact(i).get_first_name().size() > 10)
				{
					std::cout << phone_book.get_contact(i).get_first_name().substr(0, 9);
					std::cout << ".";
				}
				else
				{
					std::cout.width(10);
					std::cout << std::right << phone_book.get_contact(i).get_first_name();
				}
				std::cout << "|";
				if (phone_book.get_contact(i).get_last_name().size() > 10)
				{
					std::cout << std::right << phone_book.get_contact(i).get_last_name().substr(0, 9);
					std::cout << ".";
				}
				else
				{
					std::cout.width(10);
					std::cout << std::right << phone_book.get_contact(i).get_last_name();
				}
				std::cout << "|";
				if (phone_book.get_contact(i).get_nick_name().size() > 10)
				{
					std::cout << std::right << phone_book.get_contact(i).get_nick_name().substr(0, 9);
					std::cout << ".";
				}
				else
				{
					std::cout.width(10);
					std::cout << std::right << phone_book.get_contact(i).get_nick_name();
				}
				std::cout << "\n";
			}

			std::cout << "\n===========================================\n\n";
		}
		else if (cmd == "EXIT")
			break ;
		else
		{
			std::cout << "You must enter one of the following three commands\n";
			std::cout << "ADD | SEARCH | EXIT \n\n";
		}
	}
	return (0);
}
