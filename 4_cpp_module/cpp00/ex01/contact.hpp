/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:05:49 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/14 20:11:32 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <cstring>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string darkest_secret;
	public:
		Contact();
		Contact(std::string first_name, std::string last_name, \
			std::string nick_name, std::string phone_number, std::string darkest_secret);
		~Contact();

		void	print_first_name();
		void	print_last_name();
		void	print_nick_name();
};

#endif
