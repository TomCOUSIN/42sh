/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** basic_percent
*/

#include <stdlib.h>
#include "my.h"

int	percent_d(va_list ap)
{
	int nb = va_arg(ap, int);
	my_put_nbr(nb);
	return (0);
}

int	percent_s(va_list ap)
{
	char *str = va_arg(ap, char*);
	my_putstr(str);
	return (0);
}

int	percent_char(va_list ap)
{
	char arg = (char)va_arg(ap, int);
	my_putchar(arg);
	return (0);
}

int     percent_b(va_list ap)
{
	unsigned int nb = va_arg(ap, unsigned int);
	char *by = malloc(sizeof(char) * (64));
	int i = 0;

	if (by == NULL)
		return (84);
	while (nb != 0) {
		if (nb % 2 == 0) {
			by[i++] = '0';
		}
		else if (nb % 2 == 1) {
			by[i++] = '1';
		}
		nb = nb / 2;
	}
	by[i] = '\0';
	my_revstr(by);
	my_putstr(by);
	free(by);
	return (0);
}

int    percent_o(va_list ap)
{
	int src = va_arg(ap, int);
	int nb_decade = src / 8;
	int rest = src - nb_decade * 8;
	int dest = nb_decade * 10 + rest;

	my_put_nbr(dest);
	return (0);
}
