/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:22:15 by seojchoi          #+#    #+#             */
/*   Updated: 2023/03/23 17:14:47 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putnbr(int nbr);
int	ft_putstr(char *s);
int	ft_putnbr_u(unsigned int nbr);
int	ft_putp(unsigned long long ptr);
int	ft_putnbr_hex(unsigned int nbr, char type);

#endif
