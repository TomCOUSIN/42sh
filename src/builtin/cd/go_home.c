/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** Use cd with nothing (going to home)
*/

#include <sys/types.h>
#include <dirent.h>
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

static	int	change_to_home(char **env)
{
	int	array_index = find_env_variable(env, "HOME");
	int	home_index = 0;
	char	*home = NULL;
	char	*copy = NULL;
	int	index = 0;

	copy = my_strdup(env[array_index]);
	home = malloc(sizeof(char) * my_strlen(copy) + 1);
	if (home == NULL)
		return (84);
	index = go_to_equal(copy);
	while (copy[index] != '\0') {
		home[home_index] = copy[index];
		home_index = home_index + 1;
		index = index + 1;
	}
	home[home_index] = '\0';
	chdir(home);
	free(home);
	free(copy);
	return (0);
}

static	int	change_oldpwd(char **env)
{
	int	array_index = find_env_variable(env, "OLDPWD");
	char	*cmd[] = { "nothing", "OLDPWD", NULL };
	char	*path = NULL;
	char	buff[256];

	path = getcwd(buff, sizeof(buff));
	if (array_index != -1) {
		change_a_variable("OLDPWD", path, env);
	}
	else {
		add_empty_var(cmd, env);
		change_a_variable("OLDPWD", path, env);
	}
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

char	**go_home(char **env, int *status)
{
	int	array_index = find_env_variable(env, "HOME");

	if (array_index != -1) {
		change_oldpwd(env);
		change_to_home(env);
		change_pwd(env);
	}
	else {
		write(2, "cd: No home directory.\n", 23);
		*status = -1;
	}
	return (env);
}
