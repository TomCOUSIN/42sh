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
# include "history.h"
# include "alias.h"
# include "line.h"
# include "my.h"
# include "sh.h"

static	int	stop_shell(char *str, shell_t *shell, int *status)
{
	char	**cmd = my_str_to_word_array(str);

	if (cmd && my_strcmp(cmd[0], "exit") == 0 && cmd[1]) {
		write(2, "exit: Expression Syntax.\n", 25);
		*status = 1;
		my_array_free(cmd);
		*status = 1;
		return (0);
	}
	else if (!str || my_strcmp(cmd[0], "exit") == 0) {
		free_alias(&shell->alias);
		free_history(&shell->history);
		free(shell->prompt);
		free(shell);
		free(str);
		my_array_free(cmd);
		return (1);
	}
	my_array_free(cmd);
	return (0);
}

static	int	list_handling(char *str, shell_t *shell, int *status,
	char ***env)
{
	put_first_separator(&shell->cmd);
	create_list(str, &shell->cmd);
	if (check_list(&shell->cmd) == 0) {
		check_alias(shell, status);
		execute_list(shell, env, status);
	}
	free_list(&shell->cmd);
	return (0);
}

int	shell(char ***env)
{
	shell_t	*shell = init_shell();
	int	invalid_exit = 0;
	char	*str = NULL;
	int	status = 0;

	while (1) {
		display_prompt(shell);
		str = get_line();
		if (my_strcmp(str, "") != 0 &&
		(invalid_exit = stop_shell(str, shell, &status)) == 1)
			break;
		register_command(str, &shell->history);
		if (str && my_strcmp(str, "") != 0 && invalid_exit != 84) {
			list_handling(str, shell, &status, env);
		}
		free(str);
	}
	return (status);
}
