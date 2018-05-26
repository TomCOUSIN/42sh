/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** get the ocmmand for history
*/

# include <string.h>
# include <stdlib.h>
# include "separator.h"

char	*get_command(char *command)
{
	char	*cmd = NULL;
	int	index_1 = 0;
	int	index_2 = 0;

	if (command[index_1] == '!') {
		while (command[index_1] != '\0' && command[index_1] != ' ' &&
		!is_a_separator(command[index_1]))
			index_1 = index_1 + 1;
		if (command[index_1] == '\0')
			return (NULL);
		cmd = malloc(sizeof(char) * strlen(command));
		if (cmd == NULL)
			return (NULL);
		while (command[index_1] != '\0') {
			cmd[index_2] = command[index_1];
			index_2 += 1;
			index_1 += 1;
		}
		cmd[index_2] = '\0';
		return (cmd);
	}
	return (command);
}