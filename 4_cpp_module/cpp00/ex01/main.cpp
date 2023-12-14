/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:25:09 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/14 21:35:57 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	std::string	cmd;

	PhoneBook	phone_book;
	while (1)
	{
		getline(std::cin, cmd);
		if (!std::cin)
		{
			std::cin.clear();
			clearerr(stdin);
			continue;
		}
		if (cmd == "ADD")
			phone_book.save_contact();
		else if (cmd == "SEARCH")
			phone_book.print_contact_list();
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
