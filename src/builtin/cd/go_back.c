/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** Use cd with -
*/

#include <stdlib.h>
#include <unistd.h>
#include "builtin.h"
#include "my.h"

static	int	go_to_equal(char *str)
{
	int	index = 0;

	while (str[index] != '=') {
		index = index + 1;
	}
	index = index + 1;
	return (index);
}

static	int	change_dir(char *directory)
{
	int	dir_index = 0;
	char	*copy = NULL;
	int	index = 0;

	copy = my_strdup(directory);
	free(directory);
	directory = malloc(sizeof(char) * my_strlen(copy) + 1);
	if (directory == NULL) {
		return (84);
	}
	index = go_to_equal(copy);
	while (copy[index] != '\0') {
		directory[dir_index] = copy[index];
		index = index + 1;
		dir_index = dir_index + 1;
	}
	directory[dir_index] = '\0';
	chdir(directory);
	free(copy);
	free(directory);
	return (0);
}

static	int	change_oldpwd(char **env)
{
	char	*path = NULL;
	char	buff[256];

	path = getcwd(buff, sizeof(buff));
	change_a_variable("OLDPWD", path, env);
	return (0);
}

static	int	change_pwd(char **env)
{
	char	buff[256];
	char	*path = NULL;

	path = getcwd(buff, sizeof(buff));
	change_a_variable("PWD", path, env);
	return (0);
}

char	**go_back(char **env, int *status)
{
	int	array_index = find_env_variable(env, "OLDPWD");
	char	*directory = NULL;

	if (array_index != -1) {
		directory = my_strdup(env[array_index]);
		change_oldpwd(env);
		change_dir(directory);
		change_pwd(env);
	}
	else {
		write(2, ": No such file or directory.\n", 29);
		*status = -1;
	}
	return (env);
}