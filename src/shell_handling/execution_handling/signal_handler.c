/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** signal handling
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "my.h"

int	signal_handler(int status)
{
	if (WIFSIGNALED(status)) {
		if (status == 139) {
			write(2, "Segmentation fault\n", 19);
			status = 139;
		}
		if (status == 136) {
			write(2, "Floating exception\n", 19);
			status = 136;
		}
	}
	else {
		if (status != 21504) {
			status = 0;
		}
		else {
			status = 1;
		}
	}
	return (status);
}