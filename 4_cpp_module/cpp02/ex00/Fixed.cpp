/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:58:14 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/04 17:14:04 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point_num = 0;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed_point_num = f.getRawBits();
}

Fixed& Fixed::operator = (const Fixed &f)
{
	if (this != &f)  // 자기 자신 복사하지 않도록
	{
		std::cout << "Copy assignment operator called" << std::endl;
		fixed_point_num = f.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point_num);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_point_num = raw;
}
