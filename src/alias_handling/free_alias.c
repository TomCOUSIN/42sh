/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** free the alias list
*/

# include <stdlib.h>
# include "alias.h"
# include "my.h"

int	free_alias(alias_t **alias)
{
	alias_t	*tmp = *alias;

	while (tmp != NULL) {
		free(tmp->alias);
		my_array_free(tmp->cmd);
		*alias = tmp->next;
		free(tmp);
		tmp = *alias;
	}
	return (0);
}