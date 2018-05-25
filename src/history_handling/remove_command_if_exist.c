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

	while (tmp) {
		if (strcmp(tmp->cmd, cmd) == 0 && tmp == history) {
			*history= tmp->next;
			if (*history != NULL)
				(*history)->prev = tmp->prev;
			free(tmp->cmd);
			free(tmp);
		}
		else if (strcmp(tmp->cmd, cmd) == 0) {
			tmp->prev->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			free(tmp->cmd);
			free(tmp);
		}
		tmp = tmp->next;
	}
	return (0);
}
