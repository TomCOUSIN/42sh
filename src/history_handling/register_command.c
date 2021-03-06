/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** puts a line in the history
*/

#include	<stdlib.h>
#include	<string.h>
#include	"history.h"
#include	"my.h"

void	put_spaces(int index)
{
	if (index < 10) {
		my_printf("     ");
	}
	else if (index < 100) {
		my_printf("    ");
	} else {
		my_printf("   ");
	}
}

int	show_history(hist_t *history)
{
	hist_t	*tmp = history;

	if (history != NULL) {
		do {
			put_spaces(tmp->index);
			my_printf("%i  %s\n", tmp->index, tmp->cmd);
			tmp = tmp->next;
		} while (tmp != history && tmp != NULL);
	}
	return (0);
}

static void	new_line(hist_t **history, hist_t *line)
{
	static int	index = 2;
	hist_t	*tmp = *history;

	line->index = index;
	index += 1;
	(*history)->prev = line;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	line->prev = tmp;
	tmp->next = line;
}

void	register_command(char *command, hist_t **history)
{
	static	int	index = 0;
	hist_t	*line = NULL;
	char	*cmd = NULL;

	cmd = get_command(command);
	if (cmd == NULL || strcmp(command, "") == 0)
		return;
	remove_command_if_exist(command, history);
	index = index + 1;
	line = malloc(sizeof(*line));
	if (line == NULL)
		return;
	line->cmd = my_strdup(cmd);
	line->next = NULL;
	if (*history == NULL) {
		line->index = index;
		line->prev = NULL;
		*history = line;
	} else
		new_line(history, line);
}

void	free_history(hist_t **history)
{
	hist_t	*tmp = *history;

	while (tmp != NULL) {
		(*history) = tmp->next;
		free(tmp->cmd);
		free(tmp);
		tmp = *history;
	}
}
