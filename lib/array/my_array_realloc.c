/*
** EPITECH PROJECT, 2018
** My_array_realloc
** File description:
** my_array_realloc
*/

#include <stdlib.h>
#include "my.h"

char	**my_array_realloc(char **array, int index)
{
	char	**tmp = NULL;
	int	array_index = 0;

	tmp = my_array_dup((char const **)array);
	my_array_free(array);
	array = malloc(sizeof(char *) * index + 1);
	while (tmp[array_index] != NULL) {
		array[array_index] = my_strdup(tmp[array_index]);
		array_index = array_index + 1;
	}
	array[array_index] = "\0";
	array[array_index + 1] = NULL;
	my_array_free(tmp);
	return (array);
}