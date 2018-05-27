/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** check if the list is correct
*/

# include <stdio.h>
# include "parsing.h"

int	check_list(list_t **cmd)
{
	list_t	*tmp = *cmd;

	while (tmp) {
		if (!tmp->next[1] || !tmp->next[1]->cmd ||
		!tmp->next[1]->cmd[0]) {
			dprintf(2, "Invalid null command.\n");
			return (1);
		}
		tmp = tmp->next[0];
	}
	return (0);
}