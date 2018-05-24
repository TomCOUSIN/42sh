/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** echo
*/

# include <stdio.h>
# include "builtin.h"
# include "alias.h"

char	**do_echo(char **argv, char ***env, int *status, alias_t **alias)
{
	int	display_backslash = 1;
	int	display_return = 1;

	(void) env;
	(void) alias;
	++argv;
	parse_option(argv, &display_backslash, &display_return);
	print_echo(argv, status, display_backslash, display_return);
	return (*env);
}
