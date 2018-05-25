/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** do a history command
*/

# include <string.h>
# include <unistd.h>
# include "history.h"
# include "sh.h"
# include "my.h"

int	do_history_command(char **cmd, char ***env,
	int *status, shell_t *shell)
{
	(void)env;
	(void)shell;
	if (strncmp(cmd[0], "!!", 2) == 0) {
		//*status = 0;
		//*cmd = shell->history->prev->cmd;
		//return (0);
	}
	if (strncmp(cmd[0], "!", 1) == 0) {
		//*cmd = search_history(shell->history, my_get_nbr(cmd[0]));
	}
	if (strncmp(cmd[0], "history", 7) == 0) {
		*status = show_history(shell->history);
	}
	return (0);
}
