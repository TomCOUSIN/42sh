/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** shell function for 42sh
*/

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "parsing.h"
# include "my.h"
# include "sh.h"

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

	while (1) {
		display_prompt();
		str = get_next_line(0);
		if (!str || my_strcmp(str, "exit") == 0) {
			free(str);
			break;
		}
		create_list(str, &cmd);
		status = execute_list(&cmd, env);
		// my_show_list(&cmd);
		free_list(&cmd);
		free(str);
	}
	return (status);
}
