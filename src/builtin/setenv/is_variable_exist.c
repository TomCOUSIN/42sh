/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** is_variable_exist
*/

#include <unistd.h>
#include "my.h"

int	is_variable_exist(char const **env, char const *var)
{
	int	index = 0;

	while (env[index] != NULL) {
		if (my_strncmp(env[index], var, my_strlen(var)) == 0) {
			return (1);
		}
		index = index + 1;
	}
	return (0);
}