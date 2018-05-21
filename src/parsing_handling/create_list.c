/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** create the list of cmd
*/

# include <stdlib.h>
# include "parsing.h"
# include "separator.h"
# include "my.h"

static	int	add_separator(list_t **cmd, char *str, int *index)
{
	char	*separator = NULL;
	int size = 1;

	while (is_a_separator(str[*index]) && str[*index] != '\0') {
		separator = my_realloc(separator, size);
		separator[size - 1] = str[*index];
		size = size + 1;
		*index = *index + 1;
	}
	my_put_separator(cmd, separator);
	return (0);
}

static	int	put_first_separator(list_t **cmd)
{
	char	*str = NULL;
	int	size = 1;

	str = my_realloc(str, size);
	str[size - 1] = ';';
	my_put_separator(cmd, str);
	return (0);
}

int	create_list(char *str, list_t **cmd)
{
	char	*actual_cmd = NULL;
	int	index = 0;
	int	size = 1;

	put_first_separator(cmd);
	while (str && str[index] != '\0') {
		if (!is_a_separator(str[index])) {
			actual_cmd = my_realloc(actual_cmd, size);
			actual_cmd[size - 1] = str[index];
			size = size + 1;
			index = index + 1;
		} else {
			my_put_in_list(cmd, actual_cmd);
			actual_cmd = NULL;
			size = 1;
			add_separator(cmd, str, &index);
		}
	}
	if (actual_cmd != NULL)
		my_put_in_list(cmd, actual_cmd);
	return (0);
}