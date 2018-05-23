/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** parse_option
*/

# include <unistd.h>
# include "my.h"

static int	check_valid_opt(char const *str)
{
	size_t	i = 0;

	while (str[i++]) {
		switch (str[i]) {
			case ('e'):
				break;
			case ('E'):
				break;
			case ('n'):
				break;
			default:
				return (-1);
		}
	}
	if (i == 0) {
		return (-1);
	}
	return (0);
}

static void	handle_opt(char const *str, int *display_backslash, int *display_return)
{
	while (*str) {
		switch (*str++) {
			case ('e'):
				*display_backslash = 1;
				break;
			case ('E'):
				*display_backslash = (-1);
				break;
			case ('n'):
				*display_return = (-1);
				break;
		}
	}
}

void	parse_option(char **argv, int *display_backslash, int *display_return)
{
	char const *tmp = NULL;
	int argc = my_array_len((char const **) argv);

	while (argc > 0 && *argv[0] == '-') {
		tmp = argv[0] + 1;
		if (!check_valid_opt(tmp)) {
			break;
		}
		handle_opt(tmp, display_backslash, display_return);
		--argc;
		++argv;
	}
}
