/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** overwrite a variable and set it empty
*/

#include <stdlib.h>
#include "builtin.h"
#include "my.h"

static	char	*copy_the_variable(char **cmd, char **new_env, char **env)
{
	int	array_index = find_variable_index(env, cmd, 1);
	char	*copy = NULL;
	int	index = 0;
	int	len = 0;

	copy = my_strdup(new_env[array_index]);
	free(new_env[array_index]);
	len = my_strlen(cmd[1]);
	new_env[array_index] = malloc(sizeof(char) * (len + 2));
	if (new_env[array_index] == NULL)
		return (NULL);
	while (copy[index] != '=') {
		new_env[array_index][index] = copy[index];
		index = index + 1;
	}
	new_env[array_index][index] = '=';
	index = index + 1;
	new_env[array_index][index] = '\0';
	free(copy);
	return (new_env[array_index]);
}

int	fill_variable_empty(char **cmd, char **new_env, char **env)
{
	int	array_index = find_variable_index(env, cmd, 1);

	new_env[array_index] = copy_the_variable(cmd, new_env, env);
	if (new_env[array_index] == NULL)
		return (84);
	return (0);
}