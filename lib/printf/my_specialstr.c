/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** my_putStr
*/

#include <stdlib.h>
#include "my.h"

int	char_octal(char src)
{
	char *octal = malloc(sizeof(char) * 4);
	int nb = src;
	int index = 0;

	if (octal == NULL)
		return (84);
	while (index <= 2)
		octal[index++] = '0';
	while (nb > 0) {
		octal[--index] = nb % 8 + 48;
		nb = nb / 8;
	}
	octal[3] = '\0';
	my_putchar('\\');
	my_putstr(octal);
	free(octal);
	return (0);
}

int	my_specialstr(char *str)
{
	int i = 0;

	while (str[i] != '\0' ) {
		if (str[i] < 32 || str[i] == 127) {
			char_octal(str[i++]);
		} else {
			my_putchar(str[i++]);
		}
	}
	return (0);
}
