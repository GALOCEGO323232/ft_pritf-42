/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:26:13 by kgagliar          #+#    #+#             */
/*   Updated: 2025/08/05 13:58:17 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_aux(unsigned int num, const char format)
{
	int		len;
	char	c;

	len = 0;
	if (num >= 16)
		len += ft_puthex_aux(num / 16, format);
	if ((num % 16) <= 9)
		c = (num % 16) + '0';
	else
	{
		if (format == 'x')
			c = (num % 16) - 10 + 'a';
		else
			c = (num % 16) - 10 + 'A';
	}
	len += ft_putchar(c);
	return (len);
}

int	ft_puthex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	return (ft_puthex_aux(num, format));
}
