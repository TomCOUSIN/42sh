/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** add an alias to 42shrc
*/

# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "alias.h"
# include "my.h"

char	**add_alias(char **alias, char ***env, int *status,
	alias_t **alias_struct)
{
	(void)env;
	if (!alias[1]) {
		*status = display_alias(alias_struct);
		return (*env);
	}
	if (!alias[2]) {
		*status = display_alias_content(alias[1], alias_struct);
		return (*env);
	}
	if (is_alias_exist(alias[1], alias_struct)) {
		*status = overwrite_alias(alias[1], alias, alias_struct);
	}
	else {
		*status = add_alias_node(alias_struct, alias[1], alias);
	}
	return (*env);
}