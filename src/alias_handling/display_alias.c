/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** display all alias
*/

# include <unistd.h>
# include "alias.h"
# include "my.h"

static	int	display_content(char **array)
{
	int	index = 0;
	int	parenthesis = 0;

	if (array[index + 1] != NULL) {
		my_printf("(");
		parenthesis = 1;
	}
	while (array[index] != NULL) {
		my_printf("%s", array[index]);
		if (array[index + 1] != NULL) {
			my_printf(" ");
		}
		index = index + 1;
	}
	if (parenthesis) {
		my_printf(")");
	}
	my_printf("\n");
	return (0);
}

int	display_alias(alias_t **alias)
{
	alias_t	*tmp = *alias;

	while (tmp != NULL) {
		my_printf("%s	", tmp->alias);
		display_content(tmp->cmd);
		tmp = tmp->next;
	}
	return (0);
}