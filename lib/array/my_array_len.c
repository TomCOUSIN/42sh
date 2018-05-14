/*
** EPITECH PROJECT, 2018
** My_array_len
** File description:
** my_array_len
*/

#include <unistd.h>

int	my_array_len(char const **array)
{
	int	array_len = 0;

	while (array && array[array_len] != NULL) {
		array_len = array_len + 1;
	}
	return (array_len);
}