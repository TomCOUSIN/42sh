/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** check if the command is a history's command
*/

# include <string.h>
# include "my.h"

static	const	char	*history[]	=
{
	"!!",
	"!-",
	"!",
	"history",
	NULL
};

int	check_history(char **cmd)
{
	int	index = 0;

	while (index < 4) {
		if (my_strncmp(cmd[0],
		history[index], strlen(history[index])) == 0) {
			return (1);
		}
		index = index + 1;
	}
	return (0);
}