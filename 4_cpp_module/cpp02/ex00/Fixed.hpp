/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:55:04 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/05 15:29:52 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
private:
	int fixedPointNum;
	static const int	FractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &f);    // 복사 생성자
	Fixed& operator = (const Fixed &f);    // 복사 대입 연산자
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
