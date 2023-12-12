/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:18:15 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/12 15:12:01 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

PhoneBook::PhoneBook(void) {
	this->cur_idx = 0;
}

PhoneBook::~PhoneBook(void) {}

int		PhoneBook::get_cur_idx(void)
{
	return (cur_idx);
}

Contact	PhoneBook::get_contact(int idx)
{
	return (arr[idx]);
}

void	PhoneBook::Add(Contact &new_contact)
{
	arr[cur_idx % 8] = new_contact;
	cur_idx++;
}
