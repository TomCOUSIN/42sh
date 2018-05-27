/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** check if the command is an alias
*/

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "parsing.h"
# include "alias.h"
# include "my.h"
# include "sh.h"

static	int	check_loop(list_t *tmp, alias_t *alias, shell_t *shell,
	int *status)
{
	if (find_loop(shell, alias->alias)) {
		dprintf(2, "Alias loop.\n");
		*status = -1;
		return (1);
	}
	else {
		change_array(tmp, alias, status);
	}
	return (0);
}

static	int	verify_loop(list_t *tmp, alias_t *alias,
	shell_t *shell, int *status)
{
	if (check_loop(tmp, alias, shell, status)) {
		if (tmp->prev) {
			tmp->prev->next[0] = tmp->next[0];
		}
		else {
			shell->cmd = tmp->next[0];
		}
		my_array_free(tmp->cmd);
		my_array_free(tmp->next[1]->cmd);
		free(tmp->next[1]);
		free(tmp);
	}
	return (0);
}

static	int	check_command(list_t **cmd, alias_t *alias, shell_t *shell,
	int *status)
{
	int	count = 0; 
	list_t *tmp = *cmd;

	while (tmp != NULL && count != 150) {
		if (strcmp(tmp->next[1]->cmd[0], alias->alias) == 0) {
			verify_loop(tmp, alias, shell, status);
			count += 1;
			tmp = shell->cmd;
		}
		if (tmp) {
			tmp = tmp->next[0];
		}
	}
	return (0);
}

int	check_alias(shell_t *shell, int *status)
{
	alias_t	*alias = shell->alias;

	while (alias != NULL) {
		check_command(&shell->cmd, alias, shell, status);
		alias = alias->next;
	}
	return (0);
}