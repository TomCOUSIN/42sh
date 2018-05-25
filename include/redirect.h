/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** redirection
*/

#ifndef	_REDIRECT_H_
# define	_REDIRECT_H_

#include "parsing.h"

/* in_out_handling.c_ */
int	init_pipe(list_t *separator);

/* my_pipe.c */
int	my_pipe(int *io[2], list_t *cmd);
void	rm_node(list_t *node);

/* left_redirec.c */
int	simple_left(int *io[2], list_t *cmd);
int	double_left(int *io[2], list_t *cmd);

/* right_redirection.c */
int	simple_right(int *io[2], list_t *cmd);
int	double_right(int *io[2], list_t *cmd);

#endif		/* _REDIRECT_H_ */
