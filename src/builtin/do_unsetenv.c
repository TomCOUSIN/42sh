/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** do unsetenv builtin
*/

#include <unistd.h>
#include "builtin.h"
#include "my.h"

static	int	check_star(char **cmd)
{
	int index = 0;

	while (cmd[index] != NULL) {
		if (my_strcmp(cmd[index], "*") == 0) {
			return (1);
		}
		index = index + 1;
	}
	return (0);
}

char	**do_unsetenv(char **cmd, char ***env, int *status)
{
	if (cmd[1] == NULL) {
		write(2, "unsetenv: Too few arguments.\n", 29);
		*status = 1;
	}
	else if (check_star(cmd)) {
		*env = remove_env(*env);
	}
	else {
		*env = remove_variable(cmd, env);
	}
	return (*env);
}