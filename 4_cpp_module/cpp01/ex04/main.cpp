/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:26:49 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/20 15:01:25 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <fstream>
#include <string>

void	input_error(void)
{
	std::cout << "input error\n";
}

std::string	replace_s1_to_s2(std::string str, std::string s1, std::string s2)
{
	size_t	idx;

	while (1)
	{
		idx = str.find(s1);  //  s1의 인덱스 반환
		if (idx == std::string::npos)
			break ;
		str.erase(idx, s1.size());
		str.insert(idx, s2);
	}
	return (str);
}

int main(int ac, char **av)
{
	std::string infile = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string outfile = infile + ".replace";

	if (ac != 4)
		input_error();

	std::ifstream f(infile);
	std::ofstream out(outfile);
	while (f)
	{
		std::string in_str;
		std::string out_str;

		getline(f, in_str);
		in_str += '\n';
		out_str = replace_s1_to_s2(in_str, s1, s2);
		out << out_str;
	}
	return (0);
}
