/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:22:46 by iwillmot          #+#    #+#             */
/*   Updated: 2022/02/16 17:38:15 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_find(va_list args, const char type)
{
	int	total_leng;

	total_leng = 0;

	if (format == 'c')
		total_leng += ft_putchar(va_arg(args, int));
	//else if (format 
	return (total_leng);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		total_leng;
	va_list	args;
	char	*bonus;

	i = 0;
	total_leng = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			bonus = ft_modifiers(str, i + 1);
			print_length += ft_find(args, str[i + 1]);
			i++;
		}
		else
			total_leng += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (total_leng);
}
