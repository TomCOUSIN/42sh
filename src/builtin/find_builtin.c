/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** Find the builtin and excute it
*/

#include <unistd.h>
#include "builtin.h"
#include "my.h"

static	const	char	*builtin[]	=
{
	"cd",
	"env",
	"setenv",
	"unsetenv",
	NULL
};

int	find_builtin(char **cmd, char ***env, int *status)
{
	char	**(*fptr[])(char **, char ***, int *) =
	{ &do_cd, &do_env, &do_setenv, &do_unsetenv, NULL};
	int	index = 0;

	while (index < 4) {
		if (my_strcmp(builtin[index], cmd[0]) == 0) {
			*env = (fptr[index])(cmd, env, status);
			if (*status != 1) {
				*status = 2;
			}
		}
		index = index + 1;
	}
	return (*status);
}