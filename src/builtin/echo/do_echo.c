/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** echo
*/

# include <string.h>
# include "builtin.h"
# include "alias.h"

char	**do_echo(char **argv, char ***env, int *status, alias_t **alias)
{
	int	display_return = 1;

	(void) env;
	(void) alias;
	++argv;
	if (*argv && strcmp(*argv, "-n") == 0) {
		display_return = (-1);
		++argv;
	}
	print_echo(argv, status, display_return);
	return (*env);
}
