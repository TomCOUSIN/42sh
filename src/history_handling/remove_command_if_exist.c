/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** remove a command wich is already in history
*/

# include <string.h>
# include <stdlib.h>
# include "history.h"

int	remove_command_if_exist(char *cmd, hist_t **history)
{
	hist_t	*tmp = *history;
	int	index = 0;

	while (tmp) {
		if (strcmp(tmp->cmd, cmd) == 0 && index == 0) {
			*history= tmp->next;
			free(tmp->cmd);
			free(tmp);
			return (0);
		}
		if (strcmp(tmp->cmd, cmd) == 0 && index != 0) {
			tmp->prev->next = tmp->next;
			free(tmp->cmd);
			free(tmp);
			return (0);
		}
		tmp = tmp->next;
		index = index + 1;
	}
	return (0);
}