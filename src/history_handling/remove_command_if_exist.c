/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** remove a command wich is already in history
*/

# include <string.h>
# include <stdlib.h>
# include "history.h"

static	int	remove_the_node(hist_t *tmp, char *cmd, hist_t **history)
{
	if (strcmp(tmp->cmd, cmd) == 0 && tmp == *history) {
		*history= tmp->next;
		if (*history != NULL)
			(*history)->prev = tmp->prev;
		free(tmp->cmd);
		free(tmp);
		return (1);
	}
	else if (strcmp(tmp->cmd, cmd) == 0) {
		tmp->prev->next = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = tmp->prev;
		free(tmp->cmd);
		free(tmp);
		return (1);
	}
	return (0);
}

int	remove_command_if_exist(char *cmd, hist_t **history)
{
	hist_t	*tmp = *history;

	while (tmp != NULL) {
		if (remove_the_node(tmp, cmd, history)) {
			tmp = *history;
		}
		else {
			tmp = tmp->next;
		}
	}
	return (0);
}
