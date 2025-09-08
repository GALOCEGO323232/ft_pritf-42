/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:28:18 by kgagliar          #+#    #+#             */
/*   Updated: 2025/08/05 13:46:02 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putint(unsigned int n)
{
	char	digit;
	int		count;

	count = 0;
	if (n >= 10)
		count += ft_putint(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
	count++;
	return (count);
}
