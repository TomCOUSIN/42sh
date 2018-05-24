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
# include "alias.h"
# include "line.h"
# include "my.h"
# include "sh.h"

static	int	display_prompt(void)
{
	if (isatty(0)) {
		my_printf("]> ");
	}
	return (0);
}

static	int	stop_shell(char *str, alias_t **alias)
{
	if (!str || my_strcmp(str, "exit") == 0) {
		free_alias(alias);
		free(str);
		return (1);
	}
	return (0);
}

int	shell(char ***env)
{
	alias_t	*alias = init_alias();
	list_t	*cmd = NULL;
	char	*str = NULL;
	int	status = 0;

	while (1) {
		display_prompt();
		str = get_line();
		if (stop_shell(str, &alias)) {
			break;
		}
		if (str && my_strcmp(str, "") != 0) {
			put_first_separator(&cmd);
			create_list(str, &cmd);
			//my_show_list(&cmd);
			status = execute_list(&cmd, env, &alias);
			free_list(&cmd);
		}
		free(str);
	}
	return (status);
}