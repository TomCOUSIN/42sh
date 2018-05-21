/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** find the index of a varialble in the env
*/

#include <unistd.h>
#include "my.h"

int	find_env_variable(char **env, char *variable)
{
	int	index = 0;

	while (env[index] != NULL) {
		if (my_strncmp(env[index],
		variable, my_strlen(variable)) == 0) {
			return (index);
		}
		index = index + 1;
	}
	return (-1);
}