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

static int start_exe(list_t *cmd, char ***env, alias_t **alias)
{
	int status = 0;

	find_builtin(cmd->cmd, env, &status, alias);
	if (status != 2) {
		status = check_path(cmd, *env);
	}
	else {
		status = 0;
	}
	return (status);
}

static int execute_command(list_t *cmd, char **env, alias_t **alias)
{
	int	pid_son = 0;
	int	status = 0;
	list_t	*next_cmd = NULL;

	if (cmd == NULL)
		return (0);
	pid_son = start_exe(cmd->next[CMD], &env, alias);
	if (pid_son == -1)
		return (-1);
	next_cmd = cmd->next[SEPARATOR];
	status = execute_command(next_cmd, env, alias);
	if (status != 0)
		return (status);
	waitpid(pid_son, &status, 0);
	kill(pid_son, status);
	return (signal_handler(status));
}

int	execute_list(list_t **cmd, char ***env, alias_t **alias)
{
	list_t	*tmp = *cmd;
	int	status = 0;

	status = execute_command(tmp, *env, alias);
	return (status);
}
