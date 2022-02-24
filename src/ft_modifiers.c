/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifiers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:50:25 by iwillmot          #+#    #+#             */
/*   Updated: 2022/02/24 15:25:32 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*create_malloc(const char *str, int total, int zero)
{
	int		i;
	int		x;
	char	*modif;

	i = 0;
	x = 0;
	while (str[i] != '%')
		i++;
	modif = (char *) malloc(total * sizeof(char));
	while (x + 1 < total)
	{
		if (zero == 1)
			modif[x] = '0';
		else
			modif[x] = ' ';
		x++;
	}
	modif[x] = '\0';
	return (modif);
}

int	ft_padcalc(const char *str, int i)
{
	int	num;

	num = 0;
	if ((str[i] >= '1') && (str[i] <= '9'))
	{
		num = str[i] - 48;
		i++;
	}
	while ((str[i]) && (num > 0))
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
			num = (num * 10) + (str[i] - 48);
		else
			break ;
		i++;
	}
	return (num);
}

char	*ft_modifiers(const char *str, int i)
{
	int		zero;
	int		total;
	char	*modif;

	zero = 0;
	total = 0;
	if (str[i] == '0')
		zero = 1;
	while (str[i] == '0')
		i++;
	if ((str[i] >= '1') && (str[i] <= '9'))
		total += ft_padcalc(str, i);
	modif = create_malloc(str, total + 1, zero);
	return (modif);
}
