/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** execute the last command
*/

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
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

static	int	error_last_command(shell_t *shell, int *status)
{
	if (shell->history == NULL && shell->history == NULL) {
		write(2, "0: Event not found.\n", 21);
		*status = -1;
		return (1);
	}
	return (0);
}

int	execute_last_command(shell_t *shell, int *status, char ***env)
{
	hist_t	*tmp = shell->history;
	list_t	*copy = shell->cmd;
	list_t	*new_cmd = NULL;
	char	*str = NULL;

	while (tmp && tmp->next)
		tmp = tmp->next;
	if (error_last_command(shell, status)) {
		return (1);
	}
	str = my_clean_str(strdup(tmp->cmd));
	my_printf("%s\n", str);
	put_first_separator(&new_cmd);
	str = check_str(str);
	create_list(str, &new_cmd);
	free(str);
	shell->cmd = new_cmd;
	execute_list(shell, env, status);
	free_list(&new_cmd);
	shell->cmd = copy;
	return (0);
}