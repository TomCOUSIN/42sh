/*
** EPITECH PROJECT, 2018
** My_arraydup
** File description:
** my_arraydup
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char	**my_array_dup(char const **array)
{
	char	**new_array = NULL;
	int	array_len = 0;
	int	index = 0;

	array_len = my_array_len(array);
	new_array = malloc(sizeof(char *) * (array_len + 2));
	while (array[index] != NULL) {
		new_array[index] = my_strdup(array[index]);
		index = index + 1;
	}
	new_array[index] = NULL;
	return (new_array);
}
