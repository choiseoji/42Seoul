/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:48:58 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/05 17:37:11 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
private:
	int	fixedPointNum;
	static const int	FractionalBits = 8;

public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &f);
	Fixed& operator=(const Fixed &f);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;

	// 연산자 오버로딩
	bool operator>(const Fixed op2);
	bool operator<(const Fixed op2);
	bool operator>=(const Fixed op2);
	bool operator<=(const Fixed op2);
	bool operator==(const Fixed op2);
	bool operator!=(const Fixed op2);

	Fixed operator+(const Fixed op2);
	Fixed operator-(const Fixed op2);
	Fixed operator*(const Fixed op2);
	Fixed operator/(const Fixed op2);

	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int x);
	Fixed operator--(int x);
};

std::ostream	&operator<<(std::ostream &os, const Fixed &f);

#endif
