/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:25:37 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/23 21:11:04 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <iostream>

 int main(void)
 {
	std::string str;
	str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;
	std::string &stringREF = str;

	// print address
	std::cout << "str의 address : " << &str << std::endl;
	std::cout << "stringPTR의 address : " << stringPTR << std::endl;
	std::cout << "stringREF의 address : " << &stringREF << std::endl;

	std::cout << std::endl;
	// print value
	std::cout << "str의 value : " << str << std::endl;
	std::cout << "stringPTR의 value : " << *stringPTR << std::endl;
	std::cout << "stringREF의 value : " << stringREF << std::endl;
	return (0);
 }
