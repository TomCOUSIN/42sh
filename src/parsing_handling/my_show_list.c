/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** show th elinked list
*/

# include <unistd.h>
# include "parsing.h"
# include "my.h"

static	int	other_sens(list_t **cmd)
{
	list_t	*tmp = *cmd;
	int	index = 0;

	while (tmp->next[0] != NULL) {
		index = index + 1;
		tmp = tmp->next[0];
	}
	my_printf("Et dans l'autre sens ?\n");
	while (index > -1) {
		my_array_show((char const **)tmp->cmd);
		if (tmp->next[1]) {
			my_printf("tmp->next[1].cmd:\n");
			my_array_show((char const **)tmp->next[1]->cmd);
		}
		tmp = tmp->prev;
		index = index - 1;
	}
	return (0);
}

int	my_show_list(list_t **cmd)
{
	list_t	*tmp = *cmd;

	while (tmp != NULL) {
		my_array_show((char const **)tmp->cmd);
		if (tmp->next[1]) {
			my_printf("tmp->next[1].cmd:\n");
			my_array_show((char const **)tmp->next[1]->cmd);
		}
		tmp = tmp->next[0];
	}
	other_sens(cmd);
	return (0);
}