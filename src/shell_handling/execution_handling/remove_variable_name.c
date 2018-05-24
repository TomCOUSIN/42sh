/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** remove the variable name
*/

# include <stdlib.h>
# include <string.h>
# include "my.h"

char	*remove_variable_name(char *var)
{
	int	index = 5;
	char	*copy = malloc(sizeof(char) * strlen(var));

	while (var[index] != '\0') {
		copy[index - 5] = var[index];
		index = index + 1;
	}
	copy[index - 5] = ':';
	index = index + 1;
	copy[index - 5] = '\0';
	free(var);
	var = strdup(copy);
	free(copy);
	return (var);
}