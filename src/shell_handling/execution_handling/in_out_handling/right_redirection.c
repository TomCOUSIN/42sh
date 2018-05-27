/*
** EPITECH PROJECT, 2018
** right rediretion
** File description:
**
*/

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "redirect.h"
#include "my.h"

int simple_right(int io[2], list_t *cmd)
{
	char *file_name = cmd->next[SEPARATOR]->next[CMD]->cmd[0];
	int mod = O_WRONLY;
	int fd = open(file_name, mod);

	if (fd == -1) {
		my_printf("%s: no such file o directorie\n", file_name);
		return (-1);
	}
	io[OUTP] = fd;
	rm_node(cmd->next[SEPARATOR]);
	return (1);
}

int double_right(int io[2], list_t *cmd)
{
	char *file_name = cmd->next[SEPARATOR]->next[CMD]->cmd[0];
	int mod = O_WRONLY | O_APPEND;
	int fd = open(file_name, mod);

	printf("file name %s\n", file_name);
	if (fd == -1) {
		my_printf("%s: no such file o directorie\n", file_name);
		return (-1);
	}
	io[OUTP] = fd;
	rm_node(cmd->next[SEPARATOR]);
	return (1);
}
