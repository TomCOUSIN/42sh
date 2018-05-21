/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** modify env
*/

#include "builtin.h"

char	**modify_env(char **cmd, char **env)
{
	if (is_variable_exist((char const **)env, (char const *)cmd[1])) {
		env = overwrite_var(cmd, env);
	}
	else {
		env = create_new_var(cmd, env);
	}
	return (env);
}