/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** create a new variable and set it empty
*/

#include "my.h"

int	create_new_var_empty(char **cmd, char **new_env, char **env)
{
	int	index = my_array_len((char const **)env);
	int	var_len = my_strlen(cmd[1]);

	new_env[index] = my_strdup(cmd[1]);
	new_env[index] = my_realloc(new_env[index], var_len + 1);
	new_env[index][var_len] = '=';
	new_env[index][var_len + 1] = '\0';
	return (0);
}