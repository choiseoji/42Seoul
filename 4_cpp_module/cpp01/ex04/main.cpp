/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:26:49 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/19 20:10:36 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void input_error(void)
{

}

int main(int ac, char **av)
{
	std::string filename;
	std::string s1, s2;
	std::ifstream	ifs;

	if (ac != 4)
		input_error();
	else
	{
		// filename = av[1];
		// s1 = av[2];
		// s2 = av[3];

		// ifs.open("test.txt");
		// while (ifs)
		// {
		// 	std::string s;

		// 	getline(ifs, s);
		// 	std::cout << s;
		// }
		// ifs.close();
	}
	return (0);
}
