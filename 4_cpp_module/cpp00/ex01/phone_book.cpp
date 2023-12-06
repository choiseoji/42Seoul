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

class Contact
{
	public:
		Contact();
		Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret);

		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string darkest_secret;
};

Contact::Contact(void) {}

Contact::Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nick_name = nick_name;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

// PhoneBook은 8개의 contact를 저장할 수 있다
// 9번째 contact는 첫번째 contact 자리를 대체한다
class PhoneBook
{
	private:
		int		cur_idx;
	public:
		PhoneBook();   // 생성자
		Contact arr[8];

		void	Add(Contact &);
};

PhoneBook::PhoneBook() {}

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

	PhoneBook 	phone_book;   // 객체 생성
	while (1)
	{
		getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			std::cout << "\n==========add===========\n\n";
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
			std::cout << "\n===========save===========\n\n";

			Contact new_contact = Contact(first_name, last_name, nick_name, phone_number, darkest_secret);   // 새로운 객체 생성
			phone_book.Add(new_contact);
		}
		else if (cmd == "SEARCH")
		{
			std::cout << "\n=========search=========\n\n";
			for(int i = 0; i < 8; i++)
			{
				std::cout << phone_book.arr[i].first_name << "\n";
			}
			std::cout << "\n==========================\n\n";
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
