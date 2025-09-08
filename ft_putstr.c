/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:31:01 by kgagliar          #+#    #+#             */
/*   Updated: 2025/08/05 16:10:54 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		count = 6;
	}
	else
	{
		while (*str)
		{
			write(1, str++, 1);
			count++;
		}
	}
	return (count);
}
