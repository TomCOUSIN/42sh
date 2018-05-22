/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** free the alias list
*/

# include <stdlib.h>
# include "alias.h"

int	free_alias(alias_t **alias)
{
	alias_t	*tmp = *alias;

	while (tmp != NULL) {
		free(tmp->alias);
		free(tmp->cmd);
		*alias = tmp->next;
		free(tmp);
		tmp = *alias;
	}
	return (0);
}