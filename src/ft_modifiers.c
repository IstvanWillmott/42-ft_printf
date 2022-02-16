/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifiers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:50:25 by iwillmot          #+#    #+#             */
/*   Updated: 2022/02/16 17:38:07 by iwillmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	create_malloc(const char str, int total, int *zero)
{
	int		i;
	char	*modif;

	i = 0;
	modif = malloc(total * sizeof(char));
	if (modif[i] == '+')
}

int	ft_padcalc(const char *str, int i)
{
	int	num;

	num = 0;
	while (str[i] == '0')
		i++;
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
	int		*zero;
	int		total;
	char	*modif;

	zero = 0;
	total = 0;
	if ((total == 0) && (zero == 0))
		if (str[i] == '0')
			zero == 1;
	if ((str[i] >= '0') && (str[i] <= '9'))
		total += ft_padcalc(str, i);
	else if ((str[i] == '+') || (str[i] == '#') || (str[i] == '-')
		|| (str[i] == ' ') || (str[i] == '%'))
		total++;
	modif = create_malloc(str, total, zero); 
	return(modif);
}
