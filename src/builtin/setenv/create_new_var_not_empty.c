/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** create a new variable and set it
*/

#include <stdlib.h>
#include "my.h"

static	char	*copy_variable(char **cmd, char **new_env, char **env)
{
	int	array_index = my_array_len((char const **)env);
	int	index = 0;

	while (cmd[1][index] != '\0') {
		new_env[array_index][index] = cmd[1][index];
		index = index + 1;
	}
	new_env[array_index][index] = '=';
	return (new_env[array_index]);
}

static	char	*copy_content(char **cmd, char **new_env, char **env)
{
	int	array_index = my_array_len((char const **)env);
	int	var_index = 0;
	int	index = 0;

	while (new_env[array_index][var_index] != '=') {
		var_index = var_index + 1;
	}
	var_index = var_index + 1;
	while (cmd[2][index] != '\0') {
		new_env[array_index][var_index] = cmd[2][index];
		index = index + 1;
		var_index = var_index + 1;
	}
	new_env[array_index][var_index] = '\0';
	return (new_env[array_index]);
}

int	create_new_var_not_empty(char **cmd, char **new_env, char **env)
{
	int	array_index = my_array_len((char const **)env);
	int	len = 0;

	len = my_strlen(cmd[1]) + my_strlen(cmd[2]);
	new_env[array_index] = malloc(sizeof(char) * (len + 2));
	if (new_env[array_index] == NULL)
		return (84);
	new_env[array_index] = copy_variable(cmd, new_env, env);
	new_env[array_index] = copy_content(cmd, new_env, env);
	return (0);
}