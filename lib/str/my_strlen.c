/*
** EPITECH PROJECT, 2018
** My_strlen
** File description:
** my_strlen
*/

#include "my.h"

int	my_strlen(char const *src)
{
	int	len = 0;

	while (src && src[len] != '\0') {
		len = len + 1;
	}
	return (len);
}