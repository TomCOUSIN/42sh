/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** free the list of command
*/

# include <stdlib.h>
# include "parsing.h"
# include "my.h"

int	free_list(list_t **list)
{
	list_t	*tmp = *list;

	while (tmp != NULL) {
		my_array_free(tmp->cmd);
		if (tmp->next[1]) {
			my_array_free(tmp->next[1]->cmd);
			free(tmp->next[1]);
		}
		*list = tmp->next[0];
		free(tmp);
		tmp = *list;
	}
	return (0);
}