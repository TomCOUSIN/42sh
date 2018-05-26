/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** execute one function form the history
*/

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "separator.h"
# include "history.h"
# include "sh.h"
# include "my.h"

static	char	*check_str(char *str)
{
	char	*copy = NULL;
	int	index_1 = 0;
	int	index_2 = 0;

	if (is_a_separator(str[0])) {
		copy = malloc(sizeof(char) * strlen(str) + 1);
		while (str[index_1] != '\0' && str[index_1] != ' ' &&
		is_a_separator(str[index_1]))
			index_1 += 1;
		while (str[index_1] != '\0') {
			copy[index_2] = str[index_1];
			index_2 += 1;
			index_1 += 1;
		}
		copy[index_2] = '\0';
		free(str);
		return (copy);
	}
	return (str);
}

static	int	error_history_command(char *str, shell_t *shell, int *status,
	char **cmd)
{
	if (str == NULL) {
		if (!shell->history || !shell->history->prev) {
			dprintf(2, "%d: Event not found.\n",
				my_get_nbr(cmd[0]) + 2);
		}
		else {
			dprintf(2, "%d: Event not found.\n",
			shell->history->prev->index + my_get_nbr(cmd[0]) + 1);
		}
		*status = -1;
		return (1);
	}
	return (0);
}

int	execute_history_function(char **cmd, char ***env, int *status,
	shell_t *shell)
{
	list_t	*copy = shell->cmd;
	list_t	*new_cmd = NULL;
	char	*str = NULL;

	str = search_history(shell->history, my_get_nbr(cmd[0]));
	if (error_history_command(str, shell, status, cmd)) {
		return (1);
	}
	str = my_clean_str(strdup(str));
	str = check_str(str);
	my_printf("%s\n", str);
	put_first_separator(&new_cmd);
	create_list(str, &new_cmd);
	free(str);
	shell->cmd = new_cmd;
	execute_list(shell, env, status);
	free_list(&new_cmd);
	shell->cmd = copy;
	return (0);
}