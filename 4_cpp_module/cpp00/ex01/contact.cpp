/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:08:21 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/12 15:08:39 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "contact.hpp"

Contact::Contact(void) {}

Contact::Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nick_name = nick_name;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

Contact::~Contact(void) {}

std::string	Contact::get_first_name(void)
{
	return (first_name);
}

std::string	Contact::get_last_name(void)
{
	return (last_name);
}

std::string	Contact::get_nick_name(void)
{
	return (nick_name);
}
