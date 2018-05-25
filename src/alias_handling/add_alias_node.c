/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** add an alias node
*/

# include <stdlib.h>
# include <string.h>
# include "alias.h"
# include "my.h"

static	int	put_first_node(alias_t **alias_struct, char *alias, char **cmd)
{
	alias_t *element = NULL;

	element = malloc(sizeof(*element));
	if (element == NULL) {
		return (84);
	}
	element->alias = strdup(alias);
	element->cmd = my_array_dup((char const **)cmd);
	element->next = NULL;
	element->prev = NULL;
	*alias_struct = element;
	return (0);
}

static	int	put_node(alias_t **alias_struct, char *alias, char **cmd)
{
	alias_t *tmp = *alias_struct;
	alias_t *element = NULL;

	element = malloc(sizeof(*element));
	if (element == NULL) {
		return (84);
	}
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	element->alias = strdup(alias);
	element->cmd = my_array_dup((char const **)cmd);
	element->next = NULL;
	element->prev = tmp;
	tmp->next = element;
	return (0);
}

int	add_alias_node(alias_t **alias_struct, char *alias, char **cmd)
{
	char	**copy = 0;

	copy = transform_cmd(cmd);
	if (*alias_struct == NULL) {
		put_first_node(alias_struct, alias, copy);
	}
	else {
		put_node(alias_struct, alias, copy);
	}
	my_array_free(copy);
	return (0);
}
