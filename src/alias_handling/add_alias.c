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

int	add_alias(char **alias, alias_t **alias_struct)
{
	if (!alias[1]) {
		display_alias(alias_struct);
		return (0);
	}
	if (!alias[2]) {
		display_alias_content(alias[1], alias_struct);
		return (0);
	}
	if (is_alias_exist(alias[1], alias_struct)) {
		overwrite_alias(alias[1], alias, alias_struct);
	}
	else {
		add_alias_node(alias_struct, alias[1], alias);
	}
	return (0);
}