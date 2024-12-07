/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:02:00 by aldinc            #+#    #+#             */
/*   Updated: 2024/10/23 18:24:12 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	f_format(int num, char format)
{
	if (num >= 10 && num <= 15)
	{
		if (format == 'x')
			ft_putchar(num - 10 + 'a');
		else if (format == 'X')
			ft_putchar(num - 10 + 'A');
	}
	else
		ft_putchar(num + '0');
	return (1);
}

int	ft_print_hex(unsigned int hex, const char format)
{
	int	count;

	count = 0;
	if (hex >= 16)
	{
		count += ft_print_hex(hex / 16, format);
	}
	count += f_format(hex % 16, format);
	return (count);
}
