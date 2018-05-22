/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** display the content of an alias
*/

# include <unistd.h>
# include <string.h>
# include "alias.h"
# include "my.h"

static	int	display_content(char **array)
{
	int	index = 0;

	while (array[index] != NULL) {
		my_printf("%s", array[index]);
		if (array[index + 1] != NULL) {
			my_printf(" ");
		}
		index = index + 1;
	}
	my_printf("\n");
	return (0);
}

int	display_alias_content(char *alias, alias_t **alias_struct)
{
	alias_t	*tmp = *alias_struct;

	while (tmp != NULL) {
		if (strcmp(tmp->alias, alias) == 0) {
			display_content(tmp->cmd);
		}
		tmp = tmp->next;
	}
	return (0);
}