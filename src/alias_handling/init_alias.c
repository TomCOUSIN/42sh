/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** init the alias structure
*/

# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "alias.h"
# include "my.h"

alias_t	*init_alias(void)
{
	char	**array = NULL;
	alias_t	*alias = NULL;
	char	*line = NULL;
	int	fd = 0;

	fd = open("./.42shrc", O_RDWR);
	if (fd == -1) {
		write(2, "Error when open .42shrc\n", 24);
		return (NULL);
	}
	line = get_next_line(fd);
	while (line) {
		array = my_str_to_word_array(line);
		if (array[2]) {
			add_alias_node(&alias, array[1], array);
		}
		my_array_free(array);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (alias);
}