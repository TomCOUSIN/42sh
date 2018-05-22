/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** add a node to the list
*/

# include <stdlib.h>
# include "parsing.h"
# include "my.h"

static	int	put_first_node(list_t **cmd, char *actual_cmd)
{
	list_t *element = NULL;

	element = malloc(sizeof(*element));
	if (element == NULL) {
		return (84);
	}
	element->cmd = my_str_to_word_array(actual_cmd);
	element->next[0] = NULL;
	element->next[1] = NULL;
	element->prev = NULL;
	*cmd = element;
	return (0);
}

static	int	put_node(list_t **cmd, char *actual_cmd)
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
	element->cmd = my_str_to_word_array(actual_cmd);
	element->next[0] = NULL;
	element->next[1] = NULL;
	element->prev = NULL;
	tmp->next[1] = element;
	return (0);
}

int	my_put_in_list(list_t **cmd, char *actual_cmd)
{
	if (!actual_cmd) {
		return (84);
	}
	actual_cmd = my_clean_str(actual_cmd);
	if (*cmd == NULL) {
		put_first_node(cmd, actual_cmd);
	}
	else {
		put_node(cmd, actual_cmd);
	}
	free(actual_cmd);
	return (0);
}