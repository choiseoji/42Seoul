/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:48:58 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/04 19:56:54 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
private:
	int	fixed_point_num;
	static const int	bit = 8;

public:
	Fixed();
	Fixed(const int n);   // constant integer parameter
	Fixed(const float n);   // constant floating-point number
	Fixed(const Fixed &f);
	Fixed& operator = (const Fixed &f);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	// float	toFloat( void ) const;
	int		toInt( void ) const;
};

#endif
