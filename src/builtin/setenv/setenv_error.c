/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** setenv_error.c
*/

# include <ctype.h>
# include <string.h>
# include <unistd.h>
# include "builtin.h"

static int	is_cmd_valid(char **argv, char **env)
{
	if (argv == NULL || argv[0] == NULL) {
		return (-1);
	}
	if (strcmp(argv[0], "setenv") != 0) {
		return (-1);
	}
	if (env == NULL) {
		return (-1);
	}
	return (0);
}

static int	is_arg_valid(char **argv)
{
	int	index = 0;

	while (argv[index] != NULL) {
		index = index + 1;
	}
	if (index > 3) {
		write(2, TOO_MANY_ARG, strlen(TOO_MANY_ARG));
		return (-1);
	}
	return (0);
}

static int	is_alphanumeric(char *str)
{
	int	index = 0;

	if (isdigit(str[index]) == 0) {
		write(2, BAD_FIRST_DIGIT, strlen(BAD_FIRST_DIGIT));
		return (-1);
	}
	while (str[index] != '\0') {
		if (isalnum(str[index]) != 0 && str[index] != '_') {
			write(2, NOT_ALPHANUMERIC, strlen(NOT_ALPHANUMERIC));
			return (-1);
		}
		index = index + 1;
	}
	return (0);
}

int	setenv_error(char **argv, char **env)
{
	int	status = 0;

	status = is_cmd_valid(argv, env);
	if (status != (-1)) {
		status = is_arg_valid(argv);
	}
	if (status != (-1) && argv[1] != NULL) {
		status = is_alphanumeric(argv[1]);
	}
	return (status);
}
