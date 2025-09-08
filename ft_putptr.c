/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:30:01 by kgagliar          #+#    #+#             */
/*   Updated: 2025/08/05 14:30:11 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_aux(unsigned long num)
{
	int		len;
	char	c;

	len = 0;
	if (num >= 16)
		len += ft_putptr_aux(num / 16);
	if ((num % 16) <= 9)
		c = (num % 16) + '0';
	else
		c = (num % 16) - 10 + 'a';
	len += ft_putchar(c);
	return (len);
}

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	int				len;

	len = 0;
	addr = (unsigned long)ptr;
	if (addr == 0)
		len += write(1, "(nil)", 5);
	else
	{
		len += write(1, "0x", 2);
		len += ft_putptr_aux(addr);
	}
	return (len);
}
