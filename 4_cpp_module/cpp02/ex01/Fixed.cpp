/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:49:19 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/05 17:10:00 by seojchoi         ###   ########.fr       */
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
	float fixedPointNum;

	std::cout << "Float constructor called" << std::endl;
	fixedPointNum = roundf(num * 256);   // 어쩌피 int 로 저장되어서 소수점 날라가니깐 최대한 비슷하게 하려고 반올림 해준다
	this->fixedPointNum = fixedPointNum;
}

// 복사 생성자
Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;

	*this = f;
}

// 소멸자
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// 복사 대입 연산자 오버로딩
Fixed& Fixed::operator=(const Fixed &f)
{
	if (this != &f)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		fixedPointNum = f.fixedPointNum;
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

float Fixed::toFloat(void) const  // converts the fixed-point value to a floating-point value
{
	return ((float)this->fixedPointNum / 256);
}

int Fixed::toInt(void) const   //  converts the fixed-point value to an integer value.
{
	return (this->fixedPointNum / 256);
}
