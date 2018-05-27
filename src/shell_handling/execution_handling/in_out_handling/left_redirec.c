/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** left redirection
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "redirect.h"

int simple_left(int io[2], list_t *cmd)
{
	char *file_name = cmd->next[SEPARATOR]->next[CMD]->cmd[0];
	int mod = O_RDONLY;
	int fd = open(file_name, mod);

	if (fd == -1) {
		my_printf("%s: no such file o directorie\n", file_name);
		return (-1);
	}
	io[INPT] = fd;
	rm_node(cmd->next[SEPARATOR]);
	return (1);
}

static int write_in_pipe(char *word)
{
	int tmp[2] = {0, 1};
	char *str = NULL;

	if (pipe(tmp) == -1)
		return (-1);
	write(1,">", 1);
	str = get_next_line(0);
	while (str && my_strcmp(str, word) != 0) {
		write(tmp[1], str, my_strlen(str));
		write(tmp[1],"\n", 1);
		free(str);
		write(1,">", 1);
		str = get_next_line(0);
	}
	close(tmp[1]);
	return (tmp[0]);
}

int double_left(int io[2], list_t *cmd)
{
	char *word = cmd->next[SEPARATOR]->next[CMD]->cmd[0];
	int fd = 0;

	fd = write_in_pipe(word);
	if (fd == -1)
		return (-1);
	io[INPT] = fd;
	rm_node(cmd->next[SEPARATOR]);
	return (0);
}
