/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** change the current directory
*/

#include <stdlib.h>
#include <unistd.h>
#include "builtin.h"
#include "my.h"

char	**change_directory(char **cmd, char **env, int *status)
{
	char	**new_env = NULL;

	new_env = my_array_dup((char const **)env);
	my_array_free(env);
	if (cmd[1] == NULL) {
		new_env = go_home(new_env, status);
	}
	else if (cmd[1][0] == '-') {
		new_env = go_back(new_env, status);
	} else {
		new_env = go_to_target(cmd, new_env, status);
	}
	env = my_array_dup((char const **)new_env);
	my_array_free(new_env);
	return (env);
}
