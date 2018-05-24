/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** print_echo
*/

# include <stdio.h>
# include "my.h"

static void	process_string(char const *str, int *status, int display_backslash)
{
	char	c;

	(void) display_backslash;
	while ((c = *str++)) {
		if (c == '\\') {
			c = *str++;
		}
		if (c == '$' && *str) {
			c = *str++;
			if (c == '?') {
				my_printf("%d", *status);
				c = *str++;
			}
			else {
				my_printf("%c", '$');
			}
		}
		if (c) {
			my_printf("%c", c);
		}
	}
}

void	print_echo(char **argv, int *status, int display_backslash, int display_return)
{
	char const *tmp = NULL;
	int	argc = my_array_len((char const **) argv);

	while (argc > 0) {
		tmp = argv[0];
		process_string(tmp, status, display_backslash);
		--argc;
		++argv;
		if (argc > 0) {
			my_printf("%c", ' ');
		}
	}
	if (display_return == 1) {
		my_printf("%c", '\n');
	}
}
