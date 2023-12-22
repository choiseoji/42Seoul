/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:07:03 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/22 20:30:55 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace() { };

Replace::Replace(std::string infile, std::string s1, std::string s2)
{
	this->infile = infile;
	this->s1 = s1;
	this->s2 = s2;

	this->outfile = infile + ".replace";
	this->outstr = "";
}

Replace::~Replace() { };

void	Replace::input(void)
{
	std::ifstream	f(infile);
	while (f)
	{
		std::string	line;

		getline(f, line);
		line += '\n';
		Replace::ft_replace(line);
	}
}

void	Replace::ft_replace(std::string line)
{
	size_t	idx;

	while (1)
	{
		idx = line.find(s1);
		if (idx == std::string::npos)
			break ;
		line.erase(idx, s1.size());
		line.insert(idx, s2);
	}
	outstr += line;
}

void	Replace::output(void)
{
	std::ofstream	out(outfile);
	out << outstr;
}
