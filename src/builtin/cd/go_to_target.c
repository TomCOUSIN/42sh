/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** Use cd with go to target
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "builtin.h"
#include "my.h"

int	add_empty_var(char **cmd, char **env)
{
	int	index = my_array_len((char const **)env);
	int	var_len = my_strlen(cmd[1]);

	env[index] = my_strdup(cmd[1]);
	env[index] = my_realloc(env[index], var_len + 1);
	env[index][var_len] = '=';
	env[index][var_len + 1] = '\0';
	env[index + 1] = NULL;
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

char	**go_to_target(char **cmd, char **env, int *status)
{
	DIR	*dir = NULL;
	int	fd = 0;

	dir = opendir(cmd[1]);
	fd = open(cmd[1], O_RDONLY);
	if (fd == -1) {
		write(2, cmd[1], my_strlen(cmd[1]));
		write(2, ": No such file or directory.\n", 29);
		*status = -1;
	} else if (dir == NULL) {
		write(2, cmd[1], my_strlen(cmd[1]));
		write(2, ": Not a directory.\n", 19);
		*status = -1;
	} else {
		change_oldpwd(env);
		chdir(cmd[1]);
		change_pwd(env);
	}
	closedir(dir);
	close(fd);
	return (env);
}
