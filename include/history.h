/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** include
*/

#ifndef	HISTORY_H_
# define	HISTORY_H_

typedef struct s_hist {
	int		index;
	char		*cmd;
	struct s_hist	*next;
	struct s_hist	*prev;
} hist_t;

/* register_command.c */
void	register_command(char *command, hist_t **history);
void	free_history(hist_t **history);
void	show_history(hist_t *history);
int	check_history(char **cmd);

#endif	/* HISTORY_H_ */
