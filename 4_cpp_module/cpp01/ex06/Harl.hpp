/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:50:35 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/20 16:54:59 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

class Harl
{
private:
	void	debug();
	void	info();
	void	warning();
	void	error();
	void	insignificant();

public:
	Harl();
	~Harl();
	void	complain(std::string level);
};

#endif
