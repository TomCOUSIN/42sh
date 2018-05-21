/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** change one variable of env
*/

#include <stdlib.h>
#include "builtin.h"
#include "my.h"

static	char	*fill_content(char *var, char *new_content, int *index)
{
	int	content_index = 0;

	while (new_content[content_index] != '\0') {
		var[*index] = new_content[content_index];
		content_index = content_index + 1;
		*index = *index + 1;
	}
	var[*index] = '\0';
	return (var);
}

static	char	*fill_copy(char *var, char *new_content, int *index)
{
	char	*copy = NULL;

	copy = my_strdup(var);
	free(var);
	var = malloc(sizeof(char) *
		(my_strlen(copy) + my_strlen(new_content)) + 1);
	while (copy[*index] != '=') {
		var[*index] = copy[*index];
		*index = *index + 1;
	}
	free(copy);
	return (var);
}

int	change_a_variable(char *variable, char *new_content, char **env)
{
	int	array_index = find_env_variable(env, variable);
	int	index = 0;

	env[array_index] = fill_copy(env[array_index], new_content, &index);
	env[array_index][index] = '=';
	index = index + 1;
	env[array_index] = fill_content(env[array_index], new_content, &index);
	return (0);
}