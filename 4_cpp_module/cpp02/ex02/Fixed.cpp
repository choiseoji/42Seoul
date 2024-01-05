/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:49:19 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/05 20:34:06 by seojchoi         ###   ########.fr       */
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
	this->fixedPointNum = num * (1 << this->FractionalBits);
}

Fixed::Fixed(const float num)
{
	float fixedPointNum;

	std::cout << "Float constructor called" << std::endl;
	fixedPointNum = roundf(num * (1 << this->FractionalBits));
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

float Fixed::toFloat(void) const
{
	return ((float)this->fixedPointNum / (1 << this->FractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->fixedPointNum / (1 << this->FractionalBits));
}

// 연산자 오버로딩
// <<
std::ostream	&operator<<(std::ostream &os, const Fixed &f)
{
	os << f.toFloat();
	return (os);
}

// >
bool Fixed::operator>(const Fixed op2)
{
	if (this->fixedPointNum > op2.fixedPointNum)
		return (true);
	else
		return (false);
}

// <
bool Fixed::operator<(const Fixed op2)
{
	if (this->fixedPointNum < op2.fixedPointNum)
		return (true);
	else
		return (false);
}

// >=
bool Fixed::operator>=(const Fixed op2)
{
	if (this->fixedPointNum >= op2.fixedPointNum)
		return (true);
	else
		return (false);
}

// <=
bool Fixed::operator<=(const Fixed op2)
{
	if (this->fixedPointNum <= op2.fixedPointNum)
		return (true);
	else
		return (false);
}

// ==
bool Fixed::operator==(const Fixed op2)
{
	if (this->fixedPointNum == op2.fixedPointNum)
		return (true);
	else
		return (false);
}

// !=
bool Fixed::operator!=(const Fixed op2)
{
	if (this->fixedPointNum != op2.fixedPointNum)
		return (true);
	else
		return (false);
}

// +
Fixed Fixed::operator+(const Fixed op2)
{
	Fixed tmp;

	tmp.fixedPointNum = this->fixedPointNum + op2.fixedPointNum;
	return (tmp);
}

// -
Fixed Fixed::operator-(const Fixed op2)
{
	Fixed tmp;

	tmp.fixedPointNum = this->fixedPointNum - op2.fixedPointNum;
	return (tmp);
}

// *
Fixed Fixed::operator*(const Fixed op2)
{
	Fixed tmp;

	tmp.fixedPointNum = this->fixedPointNum * op2.fixedPointNum;
	return (tmp);
}

// /
Fixed Fixed::operator/(const Fixed op2)
{
	Fixed tmp;

	tmp.fixedPointNum = this->fixedPointNum / op2.fixedPointNum;
	return (tmp);
}

// prefix ++
Fixed& Fixed::operator++(void)
{
	this->fixedPointNum++;
	return (*this);
}

// prefix --
Fixed& Fixed::operator--(void)
{
	this->fixedPointNum--;
	return (*this);
}

// postfix ++
Fixed Fixed::operator++(int x)
{
	Fixed tmp = *this;

	x = 0;
	this->fixedPointNum++;
	return (tmp);
}

// postfix --
Fixed Fixed::operator--(int x)
{
	Fixed tmp = *this;

	x = 0;
	this->fixedPointNum--;
	return (tmp);
}
