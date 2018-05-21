/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** do setenv builtin
*/

#include <stdlib.h>
#include <unistd.h>
#include "builtin.h"
#include "my.h"

static	int	check_error_name(char **cmd, int *status)
{
	int	index = 0;

	while (cmd[1] && cmd[1][index] != '\0') {
		if ((cmd[1][index] < 'a' || cmd[1][index] > 'z') &&
		(cmd[1][index] < 'A' || cmd[1][index] > 'Z') &&
		(cmd[1][index] < '0' || cmd[1][index] > '9')
		&& cmd[1][index] != '_') {
			write(2, "setenv: Variable name must ", 27);
			write(2, "contain alphanumeric characters.\n", 33);
			*status = 1;
			return (1);
		}
		index = index + 1;
	}
	return (0);
}

static	int	check_error(char **cmd, int *status)
{
	if (my_array_len((char const **)cmd) > 3) {
		write(2, "setenv: Too many arguments.\n", 28);
		*status = 1;
		return (1);
	}
	if (cmd[1] && cmd[1][0] >= '0' && cmd[1][0] <= '9') {
		write(2, "setenv: Variable name must begin with a letter.\n",
		48);
		*status = 1;
		return (1);
	}
	if (check_error_name(cmd, status)) {
		return (1);
	}
	return (0);
}

char	**do_setenv(char **cmd, char ***env, int *status)
{
	if (check_error(cmd, status)) {
		return (*env);
	}
	else if (my_array_len((char const **)cmd) == 1) {
		my_array_show((char const **)*env);
	}
	else {
		*env = modify_env((char **)cmd, *env);
	}
	return (*env);
}