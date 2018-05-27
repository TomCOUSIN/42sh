/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** PARSING_H_
*/

# ifndef	PARSING_H_
# define	PARSING_H_

# define	INPT	0
# define	OUTP	1
# define	CMD	1
# define	SEPARATOR	0

/*
** necessary structure
*/
typedef	struct list_s
{
	char		**cmd;
	int		pipe[2];
	struct	list_s	*next[2];
	struct	list_s	*prev;
} list_t;

/*
** src/parsing_handling
*/
int	my_put_separator(list_t **cmd, char *separator);
int	my_put_in_list(list_t **cmd, char *actual_cmd);
int	check_if_last_separator(char *str, int index);
int	create_list(char *str, list_t **cmd);
int	put_first_separator(list_t **cmd);
int	my_show_list(list_t **cmd);
int	free_list(list_t **list);
int	check_list(list_t **cmd);

# endif		/* PARSING_H_ */
