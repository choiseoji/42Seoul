/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:18:15 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/06 20:12:07 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

Contact::Contact(void) {}

Contact::Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nick_name = nick_name;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

PhoneBook::PhoneBook(void) {
	this->cur_idx = 0;
}

void	PhoneBook::Add(Contact &new_contact)
{
	arr[cur_idx % 8] = new_contact;
	cur_idx++;
}

int main(void)
{
	std::string		cmd;
	std::string		first_name;
	std::string		last_name;
	std::string		nick_name;
	std::string		phone_number;
	std::string 	darkest_secret;

	PhoneBook 	phone_book;
	while (1)
	{
		getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			std::cout << "\n====================add====================\n\n";
			std::cout << "first name > ";
			getline(std::cin, first_name);
			std::cout << "last name > ";
			getline(std::cin, last_name);
			std::cout << "nick name > ";
			getline(std::cin, nick_name);
			std::cout << "phone number > ";
			getline(std::cin, phone_number);
			std::cout << "darkest secret > ";
			getline(std::cin, darkest_secret);
			std::cout << "\n===================save====================\n\n";

			Contact new_contact = Contact(first_name, last_name, nick_name, phone_number, darkest_secret);   // 새로운 객체 생성
			phone_book.Add(new_contact);
		}
		else if (cmd == "SEARCH")
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

			for(int i = 0; i < 8; i++)
			{
				std::cout.width(10);
				std::cout << std::right << i + 1;
				std::cout << "|";
				if (phone_book.arr[i].first_name.size() > 10)
				{
					std::cout << phone_book.arr[i].first_name.substr(0, 9);
					std::cout << ".";
				}
				else
				{
					std::cout.width(10);
					std::cout << std::right << phone_book.arr[i].first_name;
				}
				std::cout << "|";
				if (phone_book.arr[i].last_name.size() > 10)
				{
					std::cout << std::right << phone_book.arr[i].last_name.substr(0, 9);
					std::cout << ".";
				}
				else
				{
					std::cout.width(10);
					std::cout << std::right << phone_book.arr[i].last_name;
				}
				std::cout << "|";
				if (phone_book.arr[i].nick_name.size() > 10)
				{
					std::cout << std::right << phone_book.arr[i].nick_name.substr(0, 9);
					std::cout << ".";
				}
				else
				{
					std::cout.width(10);
					std::cout << std::right << phone_book.arr[i].nick_name;
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
