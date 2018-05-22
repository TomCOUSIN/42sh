/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** transform the double array cmd and remove alias command and is name
*/

# include <string.h>
# include <stdlib.h>
# include "my.h"

char	**transform_cmd(char **cmd)
{
	int	array_len = my_array_len((char const **)cmd);
	char	**new_cmd = malloc(sizeof(char *) * array_len);
	int	index = 2;

	while (cmd[index] != NULL) {
		new_cmd[index - 2] = strdup(cmd[index]);
		index = index + 1;
	}
	new_cmd[index - 2] = NULL;
	return (new_cmd);
}