/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** PARSING_H_
*/

# ifndef	PARSING_H_
# define	PARSING_H_

/*
** necessary structure
*/
typedef	struct list_s
{
	char		**cmd;
	struct	list_s	*next[2];
} list_t;

/*
** src/parsing_handling
*/
int	my_put_separator(list_t **cmd, char *separator);
int	my_put_in_list(list_t **cmd, char *actual_cmd);
int	create_list(char *str, list_t **cmd);
int	my_show_list(list_t **cmd);
int	free_list(list_t **list);

# endif		/* PARSING_H_ */