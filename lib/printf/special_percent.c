/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** special_percent
*/

#include "my.h"

int	percent_i(va_list ap)
{
	int nb = va_arg(ap, int);
	my_put_nbr(nb);
	return (0);
}

int	percent_x(va_list ap)
{
	int nb = va_arg(ap, int);
	low_hexa(nb);
	return (0);
}

int	percent_xb(va_list ap)
{
	int nb = va_arg(ap, int);
	up_hexa(nb);
	return (0);
}

int	percent_sb(va_list ap)
{
	char *str = va_arg(ap, char*);
	my_specialstr(str);
	return (0);
}

int	percent_u(va_list ap)
{
	unsigned int nb = va_arg(ap, unsigned int);
	my_unsigned_put_nbr(nb);
	return (0);
}
