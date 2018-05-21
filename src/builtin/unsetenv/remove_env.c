/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** Remove env
*/

#include <stdlib.h>
#include "my.h"

char	**remove_env(char **env)
{
	char	**new_env = NULL;

	my_array_free(env);
	new_env = malloc(sizeof(char *) * 2);
	new_env[0] =
	my_strdup("PATH=/bin:/usr/local/bin:/sbin:/usr/bin:/usr/sbin");
	new_env[1] = NULL;
	return (new_env);
}
