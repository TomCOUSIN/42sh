/*
** EPITECH PROJECT, 2018
** My_array_show
** File description:
** my_array_show
*/

#include <unistd.h>
#include "my.h"

int	my_array_show(char const **array)
{
	int	index = 0;

	while (array[index] != NULL) {
		my_printf("%s\n", array[index]);
		index = index + 1;
	}
	return (0);
}