/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** Find the builtin and excute it
*/

#include <stdio.h>
# include <unistd.h>
# include "builtin.h"
# include "history.h"
# include "alias.h"
# include "my.h"
# include "redirect.h"

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

static char	**(*fptr[])(char **, char ***, int *, alias_t **) = {
	&do_cd,
	&do_env,
	&do_setenv,
	&do_unsetenv,
	&add_alias,
	&remove_alias,
	&do_echo, NULL
};

static int builtin_redirect(int old[2], int new[2])
{
	if (new[INPT] != 0) {
		dup2(new[INPT], old[INPT]);
		close(new[INPT]);
	}
	if (new[OUTP] != 1) {
		dup2(new[OUTP], old[OUTP]);
		close(new[OUTP]);
	}
	return (0);
}

static int redirect(list_t *cmd, int reset)
{
	int io[2] = {0, 1};
	int save_std[2] = {0, 1};
	static int dup_io[2] = {0, 1};

	if (reset == 0) {
		get_stds(io, cmd);
		dup_io[0] = dup(0);
		dup_io[1] = dup(1);
		if (io[0] == -1 || io[1] == -1)
			return (-1);
		builtin_redirect(save_std, io);
	} else {
		builtin_redirect(save_std, dup_io);
	}
	return (0);
}

int	find_builtin(list_t *cmd, char ***env, int *status, shell_t *shell)
{
	char	**exe = cmd->next[CMD]->cmd;
	int	index = 0;

	if (check_history(exe)) {
		redirect(cmd, 0);
		do_history_command(exe, env, status, shell);
		if (*status != -1)
			*status = 2;
		redirect(cmd, 1);
	}
	while (index < 7) {
		if (my_strcmp(builtin[index], exe[0]) == 0) {
			redirect(cmd, 0);
			*env = (fptr[index])(exe, env, status, &shell->alias);
			if (*status != -1)
				*status = 2;
			redirect(cmd, 1);
		}
		index = index + 1;
	}
	return (*status);
}