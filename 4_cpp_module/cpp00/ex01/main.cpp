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

std::string	get_first_name(void)
{
	std::string	first_name;

	std::cout << "\n====================add====================\n\n";
	std::cout << "first name > ";
	getline(std::cin, first_name);
	return (first_name);
}

std::string get_last_name(void)
{
	std::string		last_name;

	std::cout << "last name > ";
	getline(std::cin, last_name);
	return (last_name);
}

std::string get_nick_name(void)
{
	std::string		nick_name;

	std::cout << "nick name > ";
	getline(std::cin, nick_name);
	return (nick_name);
}

std::string get_phone_number(void)
{
	std::string		phone_number;

	std::cout << "phone number > ";
	getline(std::cin, phone_number);
	return (phone_number);
}

std::string get_darkest_secret(void)
{
	std::string 	darkest_secret;

	std::cout << "darkest secret > ";
	getline(std::cin, darkest_secret);
	std::cout << "\n===================save====================\n\n";
	return (darkest_secret);
}

int main(void)
{
	std::string		cmd;
	std::string		first_name;
	std::string		last_name;
	std::string		nick_name;
	std::string		phone_number;
	std::string 	darkest_secret;

	PhoneBook 		phone_book;
	while (1)
	{
		getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			first_name = get_first_name();
			last_name = get_last_name();
			nick_name = get_nick_name();
			phone_number = get_phone_number();
			darkest_secret = get_darkest_secret();

			Contact new_contact = Contact(first_name, last_name, nick_name, phone_number, darkest_secret);   // 새로운 객체 생성
			phone_book.Add(new_contact);
		}
		else if (cmd == "SEARCH")
		{
			print_format();
			for(int i = 0; i < phone_book.get_cur_idx(); i++)
			{
				std::cout.width(10);
				std::cout << std::right << i + 1;
				std::cout << "|";
				if (phone_book.arr[i].get_first_name().size() > 10)
				{
					std::cout << phone_book.arr[i].get_first_name().substr(0, 9);
					std::cout << ".";
				}
				else
				{
					std::cout.width(10);
					std::cout << std::right << phone_book.arr[i].get_first_name();
				}
				std::cout << "|";
				if (phone_book.arr[i].get_last_name().size() > 10)
				{
					std::cout << std::right << phone_book.arr[i].get_last_name().substr(0, 9);
					std::cout << ".";
				}
				else
				{
					std::cout.width(10);
					std::cout << std::right << phone_book.arr[i].get_last_name();
				}
				std::cout << "|";
				if (phone_book.arr[i].get_nick_name().size() > 10)
				{
					std::cout << std::right << phone_book.arr[i].get_nick_name().substr(0, 9);
					std::cout << ".";
				}
				else
				{
					std::cout.width(10);
					std::cout << std::right << phone_book.arr[i].get_nick_name();
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
