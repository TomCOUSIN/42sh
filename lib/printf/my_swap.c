/*
** EPITECH PROJECT, 2017
** my_swap
** File description:
** task01
*/

#include "my.h"

void	my_swap(char *a, char *b)
{
	char c = 0;

	c = *b;
	*b = *a;
	*a = c;
}
