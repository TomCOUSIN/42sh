/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** get the line for 42sh
*/

# include <stdlib.h>
# include <unistd.h>
# include "alias.h"
# include "line.h"
# include "my.h"

char	*get_line(void)
{
	char	character = 0;
	char	*line = NULL;
	int	len = 1;

	while (character != '\n') {
		character = get_char();
		if (character == 0 && line == NULL)
			return (NULL);
		else if (character == 0 && line != NULL) {
			line = my_realloc(line, len);
			line[len - 1] = '\0';
			return (line);
		}
		line = my_realloc(line, len);
		line[len - 1] = character;
		len = len + 1;
	}
	line[len - 2] = '\0';
	return (line);
}