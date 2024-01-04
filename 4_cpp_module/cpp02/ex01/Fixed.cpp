/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:49:19 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/04 20:57:04 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// 생성자
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPointNum = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointNum = num * 256;  // 2^8
}

Fixed::Fixed(const float num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointNum = num * 256;  // 2^8
}

// 복사 생성자
Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPointNum = f.getRawBits();
}

// 소멸자
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// 연산자 오버로딩
Fixed& Fixed::operator=(const Fixed &f)
{
	if (this != &f)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		fixedPointNum = f.getRawBits();
	}
	return (*this);
}

// 멤버 함수
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointNum);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointNum = raw;
}
