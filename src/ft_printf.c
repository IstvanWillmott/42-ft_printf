/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:22:46 by iwillmot          #+#    #+#             */
/*   Updated: 2022/02/28 18:11:54 by iwillmot         ###   ########.fr       */
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
		total_leng += ft_putnum(va_arg(args, int), bon);
	else if (format == 's')
		total_leng += ft_putstr(va_arg(args, char *));
	else if ((format == 'x') || (format == 'X'))
		total_leng += ft_hexadecimal(va_arg(args, int), format);
	else if (format == 'u')
		total_leng += ft_putnum_unsigned(va_arg(args, int), bon);
	else if (format == '%')
		total_leng += ft_putchar('%');
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
			free(bonus);
		}
		else
			total_leng += ft_putchar(str[i]);
		i++;
	}
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
	d = 43893682;
	d2 = 2831;
	s = "nice";
	
	printf("\n");
	//character
	printf("--------CHARACTER c--------\n");
	myint = ft_printf("uhhhh %c\n", c);
	thint = printf("uhhhh %c\n", c);
	printf("me: %d - printf: %d\n", myint, thint);

	printf("\n");
	//string
	printf("--------STRING s--------\n");
	myint = ft_printf("uhhhh %s\n", s);
	thint = printf("uhhhh %s\n", s);
	printf("me: %d - printf: %d\n", myint, thint);
	
	printf("\n");
	//void ptr
	printf("--------VOID PTR p--------\n");
	//myint = ft_printf("uhhhh %s\n", s);
	thint = printf("uhhhh %p\n", s);
	//printf("me: %d - printf: %d\n", myint, thint);

	printf("\n");
	//decimal
	printf("--------DECIMAL d & i--------\n");
	myint = ft_printf("uhhhh %023d %13d\n", d, d2);
	thint = printf("uhhhh %023d %13d\n", d, d2);
	printf("me: %d - printf: %d\n", myint, thint);
	
	printf("\n");
	//unsigned int
	printf("--------UNSIGNED INT u--------\n");
	myint = ft_printf("uhhhh %23u %u\n", d, d2);
	thint = printf("uhhhh %23u %u\n", d, d2);
	printf("me: %d - printf: %d\n", myint, thint);
	
	printf("\n");
	//hex
	printf("--------HEXADECIMAL X & x--------\n");
	myint = ft_printf("uhhhh %X %x\n", d, d2);
	thint = printf("uhhhh %X %x\n", d, d2);
	printf("me: %d - printf: %d\n", myint, thint);

	printf("\n");
	//percent
	printf("--------PERCENT %%--------\n");
	myint = ft_printf("uhhhh %%\n");
	thint = printf("uhhhh %%\n");
	printf("me: %d - printf: %d\n", myint, thint);

	printf("\n");
	return (0);
}
