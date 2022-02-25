/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:21:24 by iwillmot          #+#    #+#             */
/*   Updated: 2022/02/25 18:57:42 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_putchar_hex(int c)
{
	write(1, &c, 1);
	return (1);
}

int ft_write_hex(int num, char format, int i)
{	
	if (num >= 16)
	{
		ft_write_hex(num / 16, format, i);
		ft_write_hex(num % 16, format, i);
	}
	else
	{
		if (num <= 9)
			i += ft_putchar_hex(num + '0');
		else
		{
			if (format == 'x')
				i += ft_putchar_hex(num - 10 + 'a');
			if (format == 'X')
				i += ft_putchar_hex(num - 10 + 'A');
		}
	}
	return (i);
}

int	ft_hexadecimal(int num, char format)
{
	int	i;

	i = 0;
	if (num == 0)
		return (write(1, "0", 1));
	else
		i += ft_write_hex(num, format, i);
	return (i);
}
