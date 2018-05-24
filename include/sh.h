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
# include "alias.h"

/*
** structure
*/

typedef	struct shell_s
{
	alias_t	*alias;
	list_t	*cmd;
} shell_t;

/*
** src/shell_handling
*/
int	shell(char ***env);
shell_t	*init_shell(void);

/*
** src/shell_handling/execution_handling
*/
int	execute_list(shell_t *shell, char ***env);

/*
** src/shell_handling/signal_handler.c
*/
int	signal_handler(int status);

/* exec_tools.c */
char	*my_cat_path(char *dest, char *ori);
char	*my_strcpy(char *str);

/* exec_binary.c */
int	check_path(list_t *cmd, char **env);

# endif		/* SH_H_ */
