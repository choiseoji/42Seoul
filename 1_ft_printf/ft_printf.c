/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:12:22 by seojchoi          #+#    #+#             */
/*   Updated: 2023/03/25 14:00:11 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_type(va_list ap, char type)
{
	int	len;

	len = 0;
	if (type == '%')
		len += ft_putchar('%');
	else if (type == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (type == 'd' || type == 'i')
		len += ft_putnbr(va_arg(ap, int));
	else if (type == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (type == 'p')
		len += ft_putp(va_arg(ap, unsigned long long));
	else if (type == 'u')
		len += ft_putnbr_u(va_arg(ap, unsigned int));
	else if (type == 'x' || type == 'X')
		len += ft_putnbr_hex(va_arg(ap, int), type);
	if (len < 0)
		return (-1);
	return (len);
}

int	ft_parse_format(va_list ap, char *format)
{
	int	len;
	int	check;

	len = 0;
	check = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 0)
				return (len);
			check = ft_parse_type(ap, *format);
		}
		else
		{
			check = ft_putchar(*format);
		}
		if (check < 0)
			return (-1);
		len += check;
		format++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start (ap, format);
	len = ft_parse_format(ap, (char *)format);
	va_end(ap);
	if (len < 0)
		return (-1);
	return (len);
}
