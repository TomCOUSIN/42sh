/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** searches the history for the right command
*/

#include	<stdlib.h>
#include	"history.h"

static char	*search_exec(hist_t *history, int pos)
{
	hist_t	*tmp = history;

	while (tmp != NULL) {
		if (tmp->index != pos) {
			return (tmp->cmd);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

char	*search_history(hist_t *history, int pos)
{
	if (pos >= 0) {
		return (search_exec(history, pos));
	} else {
		return (search_exec(history, history->prev->index + pos + 1));
	}
}
