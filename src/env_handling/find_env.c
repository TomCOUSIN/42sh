/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Return the index of an environnement variable.
*/

# include <stdlib.h>
# include <string.h>
# include "my.h"

int	find_env(char **env, char *str)
{
	int	index = 0;
	int	len = 0;

	if (env == NULL || str == NULL) {
		return (-1);
	}
	str = my_strjoin(str, "=");
	len = strlen(str);
	while (env[index] != NULL) {
		if (strncmp(env[index], str, len) == 0) {
			break;
		}
		index = index + 1;
	}
	free(str);
	if (env[index] == NULL) {
		return (-1);
	}
	return (index);
}
