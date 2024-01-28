/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:27:42 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/28 20:35:22 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void print_info(Bureaucrat &person)
{
	std::cout << person.getName() << "'s grade is " << person.getGrade() << std::endl;
}

int main(void)
{
	Bureaucrat SEO("seo", 10);   // 제일 높은 등급
	Bureaucrat JI("ji", 145);

	try
	{
		// SEO의 정보
		print_info(SEO);
		// SEO등급 올리기
		SEO.increment(9);
		print_info(SEO);

		// JI의 정보
		print_info(JI);
		// JI등급 내리기
		JI.decrement(6);
		print_info(JI);

	}
	catch (std::exception & e)
	{
		std::cout << e << std::endl;
	}
	return (0);
}
