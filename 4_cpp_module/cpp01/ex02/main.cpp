/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:25:37 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/18 17:35:41 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <iostream>

 int main(void)
 {
	std::string str;
	char		*stringPTR;
	// char		*stringREF;

	str = "HI THIS IS BRAIN";
	stringPTR = &str[0];   // str 첫 글자의 주소를 stringPRT에 저장

	std::cout << &str << std::endl;
	std::cout << &stringPTR << std::endl;
	// std::cout << &stringREF << std::endl;
	std::cout << str << std::endl;
	std::cout << stringPTR << std::endl;
	// std::cout << stringREF << std::endl;

	return (0);
 }
