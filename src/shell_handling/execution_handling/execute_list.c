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
# include "parsing.h"
# include "my.h"

static int my_fork(list_t *tmp, char **env)
{
	int	pid = 0;
	int	status = 0;

	pid = fork();
	if (pid == 0) {
		status = execve(tmp->cmd[0], tmp->cmd, env);
		exit(status);
	}
	else if (pid > 0) {
		return (pid);
	}
	return (-1);
}

static int execute_command(list_t *cmd, char **env)
{
	int pid_son = 0;
	int	status = 0;

	if (cmd == NULL)
		return (0);
	pid_son = my_fork(cmd, env);
	if (pid_son == -1)
		return (-1);
	if (execute_command(cmd->next[CMD], env) == -1)
		return (-1);
	waitpid(0, &status, 0);
	kill(pid_son, status);
	// check statu;
	return (status);
}

int	execute_list(list_t **cmd, char **env)
{
	list_t	*tmp = *cmd;
	int	status = 0;

	status = execute_command(tmp, env);
	return (status);
}
