/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** connextion
*/

#include <stdio.h>
#include <unistd.h>
#include "redirect.h"

static void get_stds(int io[2], list_t *cmd)
{
	list_t *prev = cmd->prev;

	if (prev == NULL)
		io[INPT] = cmd->pipe[INPT];
	else
		io[INPT] = prev->pipe[INPT];
	io[OUTP] = cmd->pipe[OUTP];
}

static void  connextion_std(int io[2])
{
	if (io[INPT] != 0) {
		dup2(io[INPT], 0);
	}
	if (io[OUTP] != 1) {
		dup2(io[OUTP], 1);
	}

}

static void close_unuse_fd(list_t *cmd)
{
	list_t *prev = cmd->prev;

	if (prev !=  NULL)
		if (prev->pipe[OUTP] != 1)
			close(prev->pipe[OUTP]);
	if (cmd->pipe[INPT] != 0)
		close(cmd->pipe[INPT]);
}

int redirect_std(list_t *cmd)
{
	int io[2] = {0, 1};

	get_stds(io, cmd);
	connextion_std(io);
	close_unuse_fd(cmd);
	return (0);
}

void close_std(list_t *cmd)
{
	int io[2] = {0, 1};

	get_stds(io, cmd);
	if (io[INPT] != 0)
		close(io[INPT]);
	if (io[OUTP] != 1)
		close(io[OUTP]);
}
