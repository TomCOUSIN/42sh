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

static	int	stop_shell(char *str, shell_t *shell)
{
	if (!str || my_strcmp(str, "exit") == 0) {
		free_alias(&shell->alias);
		free(shell);
		free(str);
		return (1);
	}
	return (0);
}

int	shell(char ***env)
{
	shell_t	*shell = init_shell();
	char	*str = NULL;
	int	status = 0;

	while (1) {
		display_prompt();
		str = get_line();
		if (stop_shell(str, shell)) {
			break;
		}
		if (str && my_strcmp(str, "") != 0) {
			put_first_separator(&shell->cmd);
			create_list(str, &shell->cmd);
			//my_show_list(&shell->cmd);
			status = execute_list(shell, env);
			free_list(&shell->cmd);
		}
		free(str);
	}
	return (status);
}