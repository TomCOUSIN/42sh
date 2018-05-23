/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** BUILTIN_H_
*/

# ifndef	BUILTIN_H_
# define	BUILTIN_H_

/*
** necessary include
*/

# include "alias.h"

/*
** builtin/
*/
	char	**do_unsetenv(char **cmd, char ***env, int *status,
		alias_t **alias);
	int	find_builtin(char **cmd, char ***env, int *status,
		alias_t **alias);
	char	**do_setenv(char **cmd, char ***env, int *status,
		alias_t **alias);
	char	**do_env(char **cmd, char ***env, int *status,
		alias_t **alias);
	char	**do_cd(char **cmd, char ***env, int *status,
		alias_t **alias);

/*
** setenv/
*/
	int	create_new_var_not_empty(char **cmd,
		char **new_env, char **env);
	int	create_new_var_empty(char **cmd, char **new_env, char **env);
	int	fill_variable_empty(char **cmd, char **new_env, char **env);
	int	find_variable_index(char **env, char **cmd, int cmd_index);
	int	fill_variable(char **cmd, char **new_env, char **env);
	int	is_variable_exist(char const **env, char const *var);
	char	**create_new_var(char **cmd, char **env);
	char	**overwrite_var(char **cmd, char **env);
	char	**modify_env(char **cmd, char **env);

/*
** unsetenv/
*/
	char	**remove_variable(char **cmd, char ***env);
	char	**remove_env(char **env);

/*
** cd/
*/
	int	change_a_variable(char *variable,
		char *new_content, char **env);
	char	**change_directory(char **cmd, char **env, int *status);
	char	**go_to_target(char **cmd, char **env, int *status);
	int	find_env_variable(char **env, char *variable);
	int	add_empty_var(char **cmd, char **env);
	char	**go_back(char **env, int *status);
	char	**go_home(char **env, int *status);

# endif		/* BUILTIN_H_ */
