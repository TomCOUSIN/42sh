/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** add a node with the separator
*/

# include <stdlib.h>
# include "parsing.h"
# include "my.h"

int	my_put_separator(list_t **cmd, char *separator)
{
	list_t *element = NULL;
	list_t *tmp = *cmd;

	element = malloc(sizeof(*element));
	if (element == NULL) {
		return (84);
	}
	while (tmp->next[0] != NULL) {
		tmp = tmp->next[0];
	}
	element->cmd = my_str_to_word_array(separator);
	element->next[0] = NULL;
	element->next[1] = NULL;
	tmp->next[0] = element;
	return (0);
}