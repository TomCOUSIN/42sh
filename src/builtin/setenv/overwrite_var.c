/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** overwrite_var
*/

#include <stdlib.h>
#include "builtin.h"
#include "my.h"

char	**overwrite_var(char **cmd, char **env)
{
	char	**new_env = NULL;

	new_env = my_array_dup((char const **)env);
	if (cmd[2] != NULL) {
		fill_variable(cmd, new_env, env);
	}
	else {
		fill_variable_empty(cmd, new_env, env);
	}
	my_array_free(env);
	return (new_env);
}