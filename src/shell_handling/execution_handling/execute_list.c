/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** execute the list of commands
*/

# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include "separator.h"
# include "builtin.h"
# include "parsing.h"
# include "alias.h"
# include "my.h"
# include "sh.h"
# include "redirect.h"

static int start_exe(list_t *cmd, char ***env, shell_t *shell, int *status)
{
	find_builtin(cmd->cmd, env, status, shell);
	if (*status != 2) {
		*status = check_path(cmd, *env);
	}
	else {
		*status = 0;
	}
	return (*status);
}

static int execute_command(list_t *cmd, shell_t *shell, char ***env,
			int *status)
{
	int	pid_son = 0;
	list_t	*prev_cmd = NULL;

	if (cmd == NULL)
		return (0);
	pid_son = start_exe(cmd->next[CMD], env, shell, status);
	if (pid_son == -1)
		return (-1);
	prev_cmd = cmd->prev;
	*status = execute_command(prev_cmd, shell, env, status);
	if (status != 0)
		return (*status);
	waitpid(pid_son, status, 0);
	kill(pid_son, *status);
	return (signal_handler(*status));
}

int	execute_list(shell_t *shell, char ***env, int *status)
{
	list_t	*tmp = shell->cmd;

	while (tmp->next[SEPARATOR] != NULL) {
		init_pipe(tmp);
		tmp = tmp->next[SEPARATOR];
	}
	*status = execute_command(tmp, shell, env, status);
	if (*status == -1)
		*status = 1;
	return (*status);
}
