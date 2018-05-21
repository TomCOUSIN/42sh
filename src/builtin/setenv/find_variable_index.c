/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** find index of the env variable
*/

#include <unistd.h>
#include "my.h"

int	find_variable_index(char **env, char **cmd, int cmd_index)
{
	int	index = 0;

	while (env[index] != NULL) {
		if (my_strncmp(env[index], cmd[cmd_index],
		my_strlen(cmd[cmd_index])) == 0) {
			return (index);
		}
		index = index + 1;
	}
	return (-1);
}