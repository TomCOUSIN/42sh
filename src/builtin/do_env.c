/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** do env builtin
*/

#include "my.h"

char	**do_env(char **cmd, char ***env)
{
	(void) cmd;
	my_array_show((char const **)*env);
	return (*env);
}