/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** overwrite alias
*/

# include <stdlib.h>
# include <string.h>
# include "alias.h"

int	overwrite_alias(char *alias, char *cmd, alias_t **alias_struct)
{
	alias_t	*tmp = *alias_struct;

	while (tmp != NULL) {
		if (strcmp(alias, tmp->alias) == 0) {
			free(tmp->cmd);
			tmp->cmd = strdup(cmd);
		}
		tmp = tmp->next;
	}
	return (0);
}