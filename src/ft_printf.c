/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:22:46 by iwillmot          #+#    #+#             */
/*   Updated: 2022/02/22 18:53:21 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_find(va_list args, const char format, char *bonus)
{
	int		total_leng;
	char	*bon;

	bon = bonus;
	total_leng = 0;
	if (format == 'c')
		total_leng += ft_putchar(va_arg(args, int));
	else if ((format == 'i') || (format == 'd'))
	{
		total_leng += ft_putstr(bon);
		total_leng += ft_putnum(va_arg(args, int));
	}
	else if (format == 's')
		total_leng += ft_putstr(va_arg(args, char *));
	else if ((format == 'x') || (format == 'X'))
		total_leng += ft_hexadecimal(va_arg(args, int), format);
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
			i++;
			bonus = ft_modifiers(str, i);
			while ((str[i] >= '0') && (str[i] <= '9'))
				i++;
			total_leng += ft_find(args, str[i], bonus);
		}
		else
			total_leng += ft_putchar(str[i]);
		i++;
	}
	free(bonus);
	va_end(args);
	return (total_leng);
}

//Testing
#include <stdio.h>

int main()
{
	char	c;
	int		d;
	int		d2;
	char	*s;

	int myint;
	int thint;

	c = 'c';
	d = 98129898;
	d2 = 1238;
	s = "nice";
	//decimal
	myint = ft_printf("uhhhh %023d %d\n", d, d2);
	thint = printf("uhhhh %023d %d\n", d, d2);
	printf("me: %d - printf: %d\n", myint, thint);
	
	//hex
	myint = ft_printf("uhhhh %X %x\n", d, d2);
	thint = printf("uhhhh %X %x\n", d, d2);
	printf("me: %d - printf: %d\n", myint, thint);
	return (0);
}
