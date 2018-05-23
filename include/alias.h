/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** ALIAS_H_
*/

# ifndef	ALIAS_H_
# define	ALIAS_H_

typedef	struct alias_s
{
	char	*alias;
	char	**cmd;
	struct alias_s *next;
	struct alias_s *prev;
} alias_t;

/*
** src/alias_handling
*/
char	**remove_alias(char **cmd, char ***env, int *status, alias_t **alias);
char	**add_alias(char **cmd, char ***env, int *status, alias_t **alias);
int	overwrite_alias(char *alias, char **cmd, alias_t **alias_struct);
int	add_alias_node(alias_t **alias_struct, char *alias, char **cmd);
int	display_alias_content(char *alias, alias_t **alias_struct);
int	is_alias_exist(char *alias, alias_t **alias_struct);
int	display_alias(alias_t **alias);
int	is_contain_quotes(char *str);
char	**transform_cmd(char **cmd);
int	free_alias(alias_t **alias);
char	*remove_quotes(char *str);
alias_t	*init_alias(void);

# endif		/* ALIAS_H_ */