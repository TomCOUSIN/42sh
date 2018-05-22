/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** put a ';' at the beginning of the string
*/

# include <unistd.h>
# include "parsing.h"
# include "my.h"

int	put_first_separator(list_t **cmd)
{
	char	*str = NULL;
	int	size = 1;

	str = my_realloc(str, size);
	str[size - 1] = ';';
	my_put_separator(cmd, str);
	return (0);
}