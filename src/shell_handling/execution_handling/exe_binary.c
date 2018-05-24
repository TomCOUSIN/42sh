/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** execution of binary
*/

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <dirent.h>
# include <stdio.h>
# include <string.h>
# include "parsing.h"
# include "my.h"
# include "builtin.h"
# include "sh.h"

static int my_fork(list_t *tmp, char **env)
{
	int	pid = 0;
	int	status = 0;

	pid = fork();
	if (pid == 0) {
		status = execve(tmp->cmd[0], tmp->cmd, env);
		exit(status);
	}
	else if (pid > 0) {
		return (pid);
	}
	return (-1);
}
static char *find_name(DIR *dir, char *name)
{
	struct dirent *stru = NULL;

	stru = readdir(dir);
	if (stru == NULL)
		return (NULL);
	while (stru) {
		if (!my_strcmp(name, stru->d_name)) {
			return (my_strcpy(stru->d_name));
		}
		stru = readdir(dir);
	}
	return (NULL);
}

static char **get_path_tab(char **env)
{
	int index = find_env_variable(env, "PATH");
	char *path = NULL;
	char **tmp = NULL;

	if (index == -1)
		return (NULL);
	path = env[index];
	tmp = my_strsplit(path, ':');
	return (tmp);
}

static char *find_path(char *name, char **env)
{
	char **path = get_path_tab(env);
	char **tmp_path = path;
	DIR *dir = NULL;
	char *ret = NULL;
	char *new_path = NULL;

	while (path != NULL && *path && !ret) {
		if (!access(*path , R_OK | X_OK)) {
			dir = opendir(*path);
			ret = find_name(dir, name);
			closedir(dir);
		}
		++path;
	}
	if (ret) {
		*(ret + my_strlen(name)) = '\0';
		new_path = my_cat_path(*(path - 1), ret);
	}
	my_array_free(tmp_path);
	return (new_path);
}

int check_path(list_t *cmd, char **env)
{
	char *name = NULL;
	char **exe = cmd->cmd;
	int pid = 0;

	if (access(exe[0], R_OK | X_OK) == 0) {
		pid = my_fork(cmd, env);
		return (pid);
	} else {
		name = find_path(exe[0], env);
		if (name) {
			free(exe[0]);
			exe[0] = name;
			pid = my_fork(cmd, env);
		} else {
			write(2, exe[0], strlen(exe[0]));
			write(2, ": Command not found.\n", 21);
			return (1);
		}
	}
	return (pid);
}
