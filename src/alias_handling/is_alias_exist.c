/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** is alias exist
*/

# include <unistd.h>
# include <string.h>
# include "alias.h"

int	is_alias_exist(char *alias, alias_t **alias_struct)
{
	alias_t	*tmp = *alias_struct;

	while (tmp != NULL) {
		if (strcmp(alias, tmp->alias) == 0) {
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}