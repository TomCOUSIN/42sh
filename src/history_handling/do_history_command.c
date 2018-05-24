/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** do a history command
*/

# include <string.h>
# include <unistd.h>
# include "sh.h"
# include "history.h"
# include "my.h"

int	do_history_command(char **cmd, char ***env,
	int *status, shell_t *shell)
{
	(void)env;
	(void)status;
	(void)shell;
	if (strncmp(cmd[0], "!!", 2) == 0) {
		my_printf("search_last_execution\n");
		//cmd = search_last_execution(shell->history);
	}
	if (strncmp(cmd[0], "!", 1) == 0) {
		my_printf("search_execution\n");
		//cmd = search_execution(shell->history, my_get_nbr(cmd[0]));
	}
	if (strncmp(cmd[0], "history", 7) == 0) {
		my_printf("show_history\n");
		//show_history(shell->history);
	}
	return (0);
}