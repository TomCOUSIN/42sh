/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** get a character
*/

# include <unistd.h>
# include "my.h"

char	get_char(void)
{
	char	character[1];

	read(0, character, 1);
	return (character[0]);
}