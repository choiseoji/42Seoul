/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:49:00 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/05 15:08:45 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::ostream	&operator<<(std::ostream &os, const Fixed &f)
{
	os << ((float)f.getRawBits() / 256);
	return (os);
}

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "=======================" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "=======================" << std::endl;
	std::cout << "a is " << a.toFloat() << " as floating-point" << std::endl;
	std::cout << "b is " << b.toFloat() << " as floating-point" << std::endl;
	std::cout << "c is " << c.toFloat() << " as floating-point" << std::endl;
	std::cout << "d is " << d.toFloat() << " as floating-point" << std::endl;

	return (0);
}
