/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** display all alias
*/

# include <unistd.h>
# include "alias.h"
# include "my.h"

int	display_alias(alias_t **alias)
{
	alias_t	*tmp = *alias;

	while (tmp != NULL) {
		my_printf("%s	%s\n", tmp->alias, tmp->cmd);
		tmp = tmp->next;
	}
	return (0);
}