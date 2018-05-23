/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** remove an alias from the list
*/

# include <stdlib.h>
# include <string.h>
# include "alias.h"
# include "my.h"

static	int	free_it(alias_t	**tmp, alias_t **alias_struct, int *index)
{
	alias_t	*to_free = *tmp;

	free(to_free->alias);
	my_array_free(to_free->cmd);
	free(to_free);
	*tmp = *alias_struct;
	*index = 0;
	return (0);
}

static	int	remove_this_alias(char *alias, alias_t **alias_struct)
{
	alias_t	*tmp = *alias_struct;
	int	index = 0;

	while (tmp != NULL) {
		if (index == 0 && strcmp(tmp->alias, alias) == 0) {
			*alias_struct = tmp->next;
			free_it(&tmp, alias_struct, &index);
		}
		else if (strcmp(tmp->alias, alias) == 0) {
			tmp->prev->next = tmp->next;
			free_it(&tmp, alias_struct, &index);
		}
		else {
			tmp = tmp->next;
			index = index + 1;
		}
	}
	return (0);
}

char	**remove_alias(char **alias, char ***env, int *status,
	alias_t **alias_struct)
{
	int	index = 1;

	while (alias[index] != NULL) {
		*status = remove_this_alias(alias[index], alias_struct);
		index = index + 1;
	}
	return (*env);
}