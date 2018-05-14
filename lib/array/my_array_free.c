/*
** EPITECH PROJECT, 2018
** My_array_free
** File description:
** my_array_free
*/

#include <unistd.h>
#include <stdlib.h>

int	my_array_free(char **array)
{
	int	index = 0;

	while (array[index] != NULL) {
		free(array[index]);
		index = index + 1;
	}
	free(array);
	return (0);
}