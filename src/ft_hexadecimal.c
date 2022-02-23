#include "../includes/ft_printf.h"

int	ft_divcalc(int num)
{
	int	res;
	int	times;

	res = 16;
	while (res * 16 < num)
		res *= 16;
	return (res);
}

int	ft_numcalc(int num)
{
	int		numlen;

	numlen = 0;
	while (num > 9)
	{
		num = num / 10;
		numlen++;
	}
	return (numlen + 1);
}

int ft_assigncor(char *new, char format)
{
	int numlen;
	int x;

	numlen = 0;
	x = 0;
	while (new[x])
	{
		if (new[x] > '9')
		{
			if (format == 'x')
				new[x] += 39;
			else
				new[x] += 7;
		}
		x++;
		numlen++;
	}
	return (numlen);
}

int ft_hexadecimal(int num, char format)
{
	int		x;
	int		divider;
	int		numlen;
	char	*new;
	
	x = 0;
	divider = ft_divcalc(num);
	numlen = ft_numcalc(num);
	new = (char *) malloc(numlen);
	while (num > 16)
	{
		new[x] = (num / divider) + 48;
		num = num - (divider * (new[x] - 48));
		divider = ft_divcalc(num);
		x++;
	}
	new[x] = (num % 16) + 48;
	while (x++ < numlen - 1)
		new[x] = '\0';
	numlen = ft_assigncor(new, format);
	ft_putstr(new);
	free(new);
	return (numlen);
}
