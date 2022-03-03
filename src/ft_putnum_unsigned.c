/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:54:48 by iwillmot          #+#    #+#             */
/*   Updated: 2022/03/01 16:29:24 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putcharuns(int c, char *i)
{
	write(1, &c, 1);
	i[0]++;
}

int	ft_putbonus(char *bonus, int g)
{
	int	i;

	i = -1;
	while (i++ != g)
		write(1, &bonus[i], 1);
	return (i);
}

int	ft_bonuscount(int num, char *bonus)
{
	int	numcount;
	int	boncount;

	numcount = 0;
	boncount = 0;
	while (num > 9)
	{
		num = num / 10;
		numcount++;
	}
	while (bonus[boncount])
		boncount++;
	numcount++;
	return (boncount - numcount - 1);
}

void	ft_recursive_print(unsigned int num, char *i)
{
	if (num >= 10)
	{
		ft_recursive_print(num / 10, i);
		ft_recursive_print(num % 10, i);
	}
	else
		ft_putcharuns(num + '0', i);
}

int	ft_putnum_unsigned(unsigned int num, char *bonus)
{
	int		total_leng;
	char	*i;
	int		g;

	total_leng = 0;
	i = malloc(1);
	i[0] = 0;
	g = ft_bonuscount(num, bonus);
	if (g >= 0)
		total_leng += ft_putbonus(bonus, g);
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_recursive_print(num, i);
	total_leng += i[0];
	return (total_leng);
}
