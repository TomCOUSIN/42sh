/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Set an environnement variable.
*/

# include "builtin.h"

int	my_setenv(char **argv, char **env)
{
	int	status = 0;

	status = setenv_error(argv, env);
	return (status);
}
