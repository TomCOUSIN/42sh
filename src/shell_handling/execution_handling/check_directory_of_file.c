/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** check if the command is a directory or a file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

int	is_a_directory(char *cmd)
{
	DIR	*dir = NULL;

	dir = opendir(cmd);
	if (dir != NULL) {
		write(2, cmd, my_strlen(cmd));
		write(2, ": Permission denied.\n", 21);
		closedir(dir);
		return (1);
	}
	return (0);
}

int	is_a_file(char *cmd)
{
	int	fd = 0;

	fd = open(cmd, O_RDONLY);
	if (fd != -1) {
		write(2, cmd, my_strlen(cmd));
		write(2, ": Permission denied.\n", 21);
		close(fd);
		return (1);
	}
	return (0);
}