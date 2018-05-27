/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** change an array alias
*/

# include <string.h>
# include <stdlib.h>
# include "parsing.h"
# include "alias.h"
# include "my.h"
# include "sh.h"

static	int	fill_alias(char **new_cmd, int *index_1, alias_t *alias)
{
	int	index_2 = 0;

	while (alias->cmd[index_2] != NULL) {
		new_cmd[*index_1] = strdup(alias->cmd[index_2]);
		index_2 += 1;
		*index_1 = *index_1 + 1;
	}
	return (0);
}

static	int	fill_command(char **new_cmd, int *index_1, list_t *tmp)
{
	int	index_2 = 1;

	while (tmp->next[1]->cmd[index_2] != NULL) {
		new_cmd[*index_1] = strdup(tmp->next[1]->cmd[index_2]);
		index_2 += 1;
		*index_1 = *index_1 + 1;
	}
	return (0);
}

int	change_array(list_t *tmp, alias_t *alias, int *status)
{
	char	**new_cmd = NULL;
	int	index_1 = 0;

	new_cmd = malloc(sizeof(char *) *
	(my_array_len((char const **)tmp->next[1]->cmd) +
	my_array_len((char const **)alias->cmd)) + 1);
	fill_alias(new_cmd, &index_1, alias);
	fill_command(new_cmd, &index_1, tmp);
	new_cmd[index_1] = NULL;
	my_array_free(tmp->next[1]->cmd);
	tmp->next[1]->cmd = my_array_dup((char const **)new_cmd);
	my_array_free(new_cmd);
	*status = 0;
	return (0);
}