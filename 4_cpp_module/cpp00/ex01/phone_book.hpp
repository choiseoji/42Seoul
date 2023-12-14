/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:08:10 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/12 15:11:39 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "contact.hpp"

class PhoneBook
{
	private:
		int		cur_idx;
		Contact	contact[8];
	public:
		PhoneBook();
        ~PhoneBook();

		int		get_cur_idx();
		void	Add(Contact &);
		Contact	get_contact(int idx);
};

#endif
