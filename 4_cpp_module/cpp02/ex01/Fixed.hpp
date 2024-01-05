/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:48:58 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/05 15:04:30 by seojchoi         ###   ########.fr       */
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
	static const int	FractionalBits = 8;  // 32비트의 뒤에 8비트는 소수점 자리로 사용하겠다!

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
};

#endif
