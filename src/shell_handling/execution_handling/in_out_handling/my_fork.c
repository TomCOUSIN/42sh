/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** my_pipe
*/

#include <stdlib.h>
#include <unistd.h>
#include "parsing.h"
#include "my.h"

void rm_node(list_t *node)
{
	list_t *next = node->next[SEPARATOR];
	list_t *prev = node->prev;

	if (prev != NULL)
		prev->next[SEPARATOR] = next;
	if (next != NULL)
		next->prev = prev;
	if (node->next[CMD]) {
		my_array_free(node->next[CMD]->cmd);
		free(node->next[CMD]);
	}
	my_array_free(node->cmd);
	free(node);
}

int my_pipe(int *io[], __attribute__((unused)) list_t *cmd)
{
	if (pipe(*io) == -1)
		return (-1);
	return (0);
}
