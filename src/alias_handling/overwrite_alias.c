/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** overwrite alias
*/

# include <stdlib.h>
# include <string.h>
# include "alias.h"
# include "my.h"

int	overwrite_alias(char *alias, char **cmd, alias_t **alias_struct)
{
	alias_t	*tmp = *alias_struct;
	char	**copy = NULL;

	copy = transform_cmd(cmd);
	while (tmp != NULL) {
		if (strcmp(alias, tmp->alias) == 0) {
			my_array_free(tmp->cmd);
			tmp->cmd = my_array_dup((char const **)copy);
		}
		tmp = tmp->next;
	}
	my_array_free(copy);
	return (0);
}