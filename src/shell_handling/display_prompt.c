/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** display the prompt
*/

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "my.h"

static	char	*get_prompt(char *str)
{
	char	*prompt = NULL;
	int	index = 12;
	int	size = 1;

	while (str[index] != '"') {
		index = index + 1;
	}
	index = index + 1;
	while (str[index] != '\0' && str[index] != '"') {
		prompt = my_realloc(prompt, size);
		prompt[size - 1] = str[index];
		size = size + 1;
		index = index + 1;
	}
	prompt[size - 1] = '\0';
	return (prompt);
}

static	char	*find_prompt(int fd)
{
	char	*prompt = NULL;
	char	*line = NULL;

	line = get_next_line(fd);
	while (line) {
		if (strncmp(line, "set prompt =", 12) == 0) {
			prompt = get_prompt(line);
			free(line);
			return (prompt);
		}
		free(line);
		line = get_next_line(fd);
	}
	prompt = malloc(sizeof(char) * 4);
	prompt[0] = ']';
	prompt[1] = '>';
	prompt[2] = ' ';
	prompt[3] = '\0';
	return (prompt);
}

int	display_prompt(void)
{
	int	fd = 0;
	char	*prompt = NULL;

	fd = open("./.42shrc", O_RDWR);
	if (fd == -1) {
		if (isatty(0)) {
			my_printf("]> ");
		}
	} else {
		prompt = find_prompt(fd);
		if (isatty(0)) {
			my_printf("%s", prompt);
		}
		free(prompt);
		close(fd);
	}
	return (0);
}