/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** execute a command with path
*/

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "parsing.h"
# include "sh.h"
# include "my.h"

int	exec_command_with_path(list_t *cmd, char **env, char **exe)
{
	char *name = NULL;
	int pid = 0;

	name = find_path(exe[0], env);
	if (name) {
		free(exe[0]);
		exe[0] = name;
		pid = my_fork(cmd, env);
	} else {
		if (is_a_file(exe[0])) {
			return (-1);
		}
		write(2, exe[0], strlen(exe[0]));
		write(2, ": Command not found.\n", 21);
		return (-1);
	}
	return (pid);
}