/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** do cd buitin
*/

#include <unistd.h>
#include "builtin.h"
#include "my.h"

char	**do_cd(char **cmd, char ***env, int *status, alias_t **alias)
{
	(void)alias;
	if (my_array_len((char const **)cmd) > 3) {
		write(2, "cd: Too many arguments.\n", 24);
		*status = -1;
		return (*env);
	}
	else {
		*env = change_directory(cmd, *env, status);
	}
	return (*env);
}
