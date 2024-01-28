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

int main(void)
{
	Bureaucrat SEO("seo", 10);   // 제일 높은 등급
	Bureaucrat JI("ji", 145);

	try
	{
		// SEO의 정보
		std::cout << SEO << std::endl;
		// SEO등급 올리기
		SEO.increment(9);
		std::cout << SEO << std::endl;

		// JI의 정보
		std::cout << JI << std::endl;
		// JI등급 내리기
		JI.decrement(6);
		std::cout << JI << std::endl;

	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
