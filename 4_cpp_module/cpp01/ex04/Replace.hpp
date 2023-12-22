/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:02:56 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/22 20:31:10 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP
# include <iostream>
# include <fstream>
# include <string>

class Replace
{
private:
	std::string	infile;
	std::string	outfile;
	std::string	s1;
	std::string	s2;

	std::string	outstr;
public:
	Replace();
	Replace(std::string infile, std::string s1, std::string s2);
	~Replace();

	void	input();
	void	ft_replace(std::string line);
	void	output();
};

#endif
