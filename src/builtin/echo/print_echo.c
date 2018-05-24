/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** print_echo
*/

# include <stdio.h>
# include "my.h"

static char const	*print_status(char const *str, char *c, int *status)
{
	*c = *str++;
	if (*c == '?') {
		my_printf("%d", *status);
	}
	else {
		my_printf("%c", '$');
	}
	return (str);
}

static char const	*print_character(char const *str, char *c)
{
	if (*c == '\\' && *str) {
		*c = *str++;
	}
	my_printf("%c", *c);
	return (str);
}

static void	process_string(char const *str, int *status)
{
	char	c;

	while ((c = *str++)) {
		if (c == '$' && *str) {
			str = print_status(str, &c, status);
			return;
		}
		else {
			str = print_character(str, &c);
		}
	}
}

void	print_echo(char **argv, int *status, int display_return)
{
	char const *tmp = NULL;
	int	argc = my_array_len((char const **) argv);

	while (argc > 0) {
		tmp = argv[0];
		process_string(tmp, status);
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
