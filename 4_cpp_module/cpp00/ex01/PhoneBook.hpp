/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:14:15 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/14 20:43:17 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
	private:
		int			idx;
		int			size;
		Contact 	contact[8];
	public:
		PhoneBook();
		~PhoneBook();

		std::string	get_info(std::string str);
		void		save_contact();
		Contact		get_contact(int idx);
		void		print_contact_list();
};

#endif
