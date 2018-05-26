/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** Find the builtin and excute it
*/

# include <unistd.h>
# include "builtin.h"
# include "history.h"
# include "alias.h"
# include "my.h"

static	const	char	*builtin[]	=
{
	"cd",
	"env",
	"setenv",
	"unsetenv",
	"alias",
	"unalias",
	"echo",
	NULL
};

int	find_builtin(char **cmd, char ***env, int *status, shell_t *shell)
{
	char	**(*fptr[])(char **, char ***, int *, alias_t **) =
	{&do_cd, &do_env, &do_setenv, &do_unsetenv, &add_alias, &remove_alias,
	&do_echo, NULL};
	int	index = 0;

	if (check_history(cmd)) {
		do_history_command(cmd, env, status, shell);
		if (*status != -1)
			*status = 2;
		return (*status);
	}
	while (index < 7) {
		if (my_strcmp(builtin[index], cmd[0]) == 0) {
			*env = (fptr[index])(cmd, env, status, &shell->alias);
			if (*status != -1)
				*status = 2;
		}
		index = index + 1;
	}
	return (*status);
}
