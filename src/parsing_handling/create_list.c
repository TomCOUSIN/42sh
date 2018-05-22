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

int	create_list(char *str, list_t **cmd)
{
	char	*actual_cmd = NULL;
	int	index = 0;
	int	quote = 0;
	int	size = 1;

	while (str && str[index] != '\0') {
		if (str[index] == '"')
			quote += 1;
		if (!is_a_separator(str[index]) || quote % 2 == 1) {
			actual_cmd = my_realloc(actual_cmd, size);
			actual_cmd[size - 1] = str[index];
			size = size + 1;
			index = index + 1;
		} else if (quote % 2 == 0) {
			my_put_in_list(cmd, actual_cmd);
			actual_cmd = NULL;
			add_separator(cmd, str, &index);
			size = 1;
		}
	}
	return (my_put_in_list(cmd, actual_cmd));
}