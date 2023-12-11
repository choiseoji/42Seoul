/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:08:10 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/10 16:26:06 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <cstring>

class Contact
{
	public:
		Contact();
		Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret);
        ~Contact();

		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string darkest_secret;
};

class PhoneBook
{
	public:
		PhoneBook();
        ~PhoneBook();

        int     cur_idx;
		Contact arr[8];

		void	Add(Contact &);
};

#endif
