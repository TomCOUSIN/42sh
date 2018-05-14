/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** shell function for 42sh
*/

# include <stdlib.h>
# include "my.h"

static	int	display_prompt(void)
{
	my_printf("$> ");
	return (0);
}

int	shell(char **env)
{
	char	*str = NULL;
	int	status = 0;

	(void)env;
	while (1) {
		display_prompt();
		str = get_next_line(0);
		if (my_strcmp(str, "exit") == 0) {
			free(str);
			break;
		}
		free(str);
	}
	return (status);
}