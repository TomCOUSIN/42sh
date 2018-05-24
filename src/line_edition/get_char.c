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
	int	nb_read = 0;

	nb_read = read(0, character, 1);
	if (nb_read == 0) {
		return (0);
	}
	return (character[0]);
}