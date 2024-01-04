/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:48:58 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/04 14:49:37 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
private:
	int	fixed_point_num;
	static const int	bit = 8;

public:
	Fixed();
	Fixed(const Fixed &f);
	Fixed& operator = (const Fixed &f);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
