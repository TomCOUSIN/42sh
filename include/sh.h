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
# include <dirent.h>
# include "parsing.h"
# include "history.h"
# include "alias.h"

/*
** structure
*/

typedef	struct shell_s
{
	alias_t	*alias;
	list_t	*cmd;
	hist_t	*history;
	int	status;
	char	*prompt;
} shell_t;

/*
** src/shell_handling
*/
int	display_prompt(shell_t *shell);
int	shell(char ***env);
shell_t	*init_shell(void);

/*
** src/shell_handling/execution_handling
*/
int	execute_list(shell_t *shell, char ***env, int *status);
char	*remove_variable_name(char *var);
int	is_a_directory(char *cmd);
int	is_a_file(char *cmd);

/*
** src/shell_handling/signal_handler.c
*/
int	signal_handler(int status);

/* exec_tools.c */
char	*my_cat_path(char *dest, char *ori);
char	*my_strcpy(char *str);

/* exec_binary.c */
int	exec_command_with_path(list_t *cmd, char **env, char **exe);
int	check_path(list_t *cmd, char **env);
char	*find_path(char *name, char **env);
int	my_fork(list_t *tmp, char **env, char **exe);

/* history */
int	execute_history_function(char **cmd, char ***env,
				int *status, shell_t *shell);
int	execute_last_command(shell_t *shell, int *status, char ***env);
int	do_history_command(char **cmd, char ***env,
			int *status, shell_t *shell);

/* alias */
int	change_array(list_t *tmp, alias_t *alias, int *status);
int	check_alias(shell_t *shell, int *status);
int	find_loop(shell_t *shell, char *save);

# endif		/* SH_H_ */
