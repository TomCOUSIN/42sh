/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** shell function for 42sh
*/

# include <stdlib.h>
# include <unistd.h>
# include "parsing.h"
# include "my.h"

static	int	display_prompt(void)
{
	char	*buf = NULL;
	size_t	size = 0;

	if (isatty(0)) {
		buf = getcwd(buf, size);
		my_printf("%s> ", buf);
	}
	free(buf);
	return (0);
}

int	shell(char **env)
{
	list_t	*cmd = NULL;
	char	*str = NULL;
	int	status = 0;

	(void)env;
	while (1) {
		display_prompt();
		str = get_next_line(0);
		create_list(str, &cmd);
		my_show_list(&cmd);
		free_list(&cmd);
		if (!str || my_strcmp(str, "exit") == 0) {
			free(str);
			break;
		}
		free(str);
	}
	return (status);
}
