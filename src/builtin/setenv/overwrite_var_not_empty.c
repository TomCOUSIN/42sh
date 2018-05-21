/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** overwrite a variable and set it
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
	len = my_strlen(cmd[1]) + my_strlen(cmd[2]);
	new_env[array_index] = malloc(sizeof(char) * (len + 2));
	if (new_env[array_index] == NULL)
		return (NULL);
	while (copy[index] != '=') {
		new_env[array_index][index] = copy[index];
		index = index + 1;
	}
	new_env[array_index][index] = '=';
	free(copy);
	return (new_env[array_index]);
}

static	char	*overwrite_content(char **cmd, char **new_env, char **env)
{
	int	array_index = find_variable_index(env, cmd, 1);
	int	var_index = 0;
	int	index = 0;

	while (new_env[array_index][index] != '=') {
		index = index + 1;
	}
	index = index + 1;
	while (cmd[2][var_index] != '\0') {
		new_env[array_index][index] = cmd[2][var_index];
		index = index + 1;
		var_index = var_index + 1;
	}
	new_env[array_index][index] = '\0';
	return (new_env[array_index]);
}

int	fill_variable(char **cmd, char **new_env, char **env)
{
	int	array_index = find_variable_index(env, cmd, 1);

	new_env[array_index] = copy_the_variable(cmd, new_env, env);
	if (new_env[array_index] == NULL)
		return (84);
	new_env[array_index] = overwrite_content(cmd, new_env, env);
	return (0);
}