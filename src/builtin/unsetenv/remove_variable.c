/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** remove a variable of the environment
*/

#include <stdlib.h>
#include "builtin.h"
#include "my.h"

static	char	**change_env(char **env, int array_index)
{
	int	array_len = my_array_len((char const **)env);
	char	**new_env = NULL;
	int	new_index = 0;
	int	index = 0;

	new_env = malloc(sizeof(char *) * (array_len + 1));
	if (new_env == NULL)
		return (env);
	while (env[index] != NULL) {
		if (index != array_index) {
			new_env[new_index] = my_strdup(env[index]);
			new_index = new_index + 1;
		}
		index = index + 1;
	}
	new_env[new_index] = NULL;
	my_array_free(env);
	return (new_env);
}

char	**remove_variable(char **cmd, char ***env)
{
	char	**new_env = NULL;
	int	array_index = 0;
	int	index = 1;

	new_env = my_array_dup((char const **)*env);
	while (cmd[index] != NULL) {
		array_index = find_variable_index(new_env, cmd, index);
		if (array_index != -1) {
			new_env = change_env(new_env, array_index);
		}
		index = index + 1;
	}
	my_array_free(*env);
	*env = my_array_dup((char const **)new_env);
	my_array_free(new_env);
	return (*env);
}