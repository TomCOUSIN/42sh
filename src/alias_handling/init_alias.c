/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** init the alias structure
*/

# include <sys/types.h>
# include <string.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "alias.h"
# include "my.h"

static	int	add_alias_from_shrc(char *line, alias_t **alias)
{
	char **array = my_str_to_word_array(line);

	if (array[2]) {
		add_alias_node(alias, array[1], array);
	}
	my_array_free(array);
	return (0);
}

alias_t	*init_alias(void)
{
	alias_t	*alias = NULL;
	char	*line = NULL;
	int	fd = 0;

	fd = open("./.42shrc", O_RDWR);
	if (fd == -1) {
		return (NULL);
	}
	line = get_next_line(fd);
	while (line) {
		if (strncmp("alias", line, strlen("alias")) == 0) {
			add_alias_from_shrc(line, &alias);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (alias);
}