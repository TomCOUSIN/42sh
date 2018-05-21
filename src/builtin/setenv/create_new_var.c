/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** create_var_env
*/

#include <stdlib.h>
#include "builtin.h"
#include "my.h"

static	char	**copy_env(char **env)
{
	char	**new_env = NULL;
	int	array_len = 0;
	int	index = 0;

	array_len = my_array_len((char const **)env);
	new_env = malloc(sizeof(char *) * (array_len + 2));
	if (new_env == NULL)
		return (NULL);
	while (index < array_len) {
		new_env[index] = my_strdup(env[index]);
		index = index + 1;
	}
	new_env[index] = "\0";
	index = index + 1;
	new_env[index] = NULL;
	return (new_env);
}

char	**create_new_var(char **cmd, char **env)
{
	char	**new_env = NULL;

	new_env = copy_env(env);
	if (cmd[2] == NULL) {
		create_new_var_empty(cmd, new_env, env);
	}
	else {
		create_new_var_not_empty(cmd, new_env, env);
	}
	my_array_free(env);
	return (new_env);
}