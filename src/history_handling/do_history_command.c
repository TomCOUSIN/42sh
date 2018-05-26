/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** do a history command
*/

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "separator.h"
# include "history.h"
# include "sh.h"
# include "my.h"

int	do_history_command(char **cmd, char ***env,
	int *status, shell_t *shell)
{
	(void)env;
	if (strcmp(cmd[0], "!!") == 0) {
		execute_last_command(shell, status, env);
		return (0);
	}
	else if (strncmp(cmd[0], "!", 1) == 0) {
		execute_history_function(cmd, env, status, shell);
		return (0);
	}
	if (strncmp(cmd[0], "history", 7) == 0) {
		*status = show_history(shell->history);
	}
	return (0);
}
