/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** show th elinked list
*/

# include <unistd.h>
# include "parsing.h"
# include "my.h"

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
	return (0);
}