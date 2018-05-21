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

static	int	execute_command(list_t *tmp, char **env)
{
	int	status = 0;
	int	pid = 0;

	pid = fork();
	if (pid == 0) {
		status = execve(tmp->cmd[0], tmp->cmd, env);
		exit(status);
	}
	else {
		waitpid(0, &status, 0);
		kill(pid, status);
	}
	return (status);
}

int	execute_list(list_t **cmd, char **env)
{
	list_t	*tmp = *cmd;

	execute_command(tmp, env);
	return (0);
}