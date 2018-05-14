/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** low_hexa
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char	low_check_modulo(int result)
{
	int i = 9;
	char dest;

	if (result > 9) {
		while (i < result) {
			dest = i - 8 + 96;
			i++;
		}
	} else {
		dest = result + 48;
	}
	return (dest);
}

char	*low_converter(int src, char *dest, int index)
{
	int result = 0;

	while (src > 0) {
		result = src % 16;
		dest[index] = low_check_modulo(result);
		index++;
		src = src / 16;
	}
	dest[index] = '\0';
	return (dest);
}

int	low_hexa(int src)
{
	char *dest = malloc(sizeof(char) * 32);
	int index = 0;

	if (dest == NULL)
		return (84);
	dest = low_converter(src, dest, index);
	my_revstr(dest);
	my_putstr(dest);
	free(dest);
	return (0);
}
