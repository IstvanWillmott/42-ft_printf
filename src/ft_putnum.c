/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:11:54 by iwillmot          #+#    #+#             */
/*   Updated: 2022/02/24 15:24:12 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_countstr(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i - 1);
}

int	ft_putnum(int str, char *bon)
{
	int		i;
	char	*new;
	int		newleng;
	int		bonleng;

	i = 0;
	new = ft_itoa(str);
	newleng = ft_countstr(new);
	bonleng = ft_countstr(bon);
	if (newleng <= bonleng)
	{
		while (newleng >= 0)
		{
			bon[bonleng] = new[newleng];
			bonleng--;
			newleng--;
		}
		i = ft_putstr(bon);
	}
	else
		i = ft_putstr(new);
	return (i);
}
