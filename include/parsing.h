/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** PARSING_H_
*/

# ifndef	PARSING_H_
# define	PARSING_H_

typedef	struct list_s
{
	char		*cmd;
	struct	list_s	*next[2];
} list_t;

# endif		/* PARSING_H_ */