/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:20:44 by kgagliar          #+#    #+#             */
/*   Updated: 2025/08/05 16:25:10 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_parser(va_list args, const char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), c));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == 'u')
		return (ft_putint(va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_print_percent());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			print;
	int			i;

	if (!format)
		return (-1);
	i = 0;
	print = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			print += ft_printf_parser(args, format[i]);
			i++;
		}
		else
		{
			print += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (print);
}
