/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** do env builtin
*/

# include "alias.h"
#include "my.h"

char	**do_env(char **cmd, char ***env, int *status, alias_t **alias)
{
	(void)cmd;
	(void)alias;
	*status = my_array_show((char const **)*env);
	return (*env);
}