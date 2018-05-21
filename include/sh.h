/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** SH_H_
*/

# ifndef	SH_H_
# define	SH_H_

/*
** necessary include
*/
# include "parsing.h"

/*
** src/shell_handling
*/
int	shell(char ***env);

/*
** src/shell_handling/execution_handling
*/
int	execute_list(list_t **cmd, char ***env);

/*
** src/shell_handling/signal_handler.c
*/
int	signal_handler(int status);

# endif		/* SH_H_ */
