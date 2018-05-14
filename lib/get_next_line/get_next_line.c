/*
** EPITECH PROJECT, 2018
** Get_next_line
** File description:
** get_next_line
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"

static char	get_character(int const fd)
{
	static char	buffer[READ_SIZE];
	static int	nb_read = 0;
	static int	index;
	char		character;

	if (nb_read == 0) {
		nb_read = read(fd, buffer, READ_SIZE);
		if (nb_read == 0) {
			return (0);
		}
		index = 0;
	}
	character = buffer[index];
	index = index + 1;
	nb_read = nb_read - 1;
	return (character);
}

static	int	check_character(char character, char *string)
{
	if (character == '\0' && string[0] == '\0') {
		free(string);
		return (1);
	}
	return (0);
}

char	*get_next_line(int const fd)
{
	char	character = get_character(fd);
	char	*string = malloc(sizeof(char) * READ_SIZE + 2);
	int	index = 0;

	if (string == NULL) {
		return (NULL);
	}
	while (character != '\n' && character != '\0') {
		string[index] = character;
		character = get_character(fd);
		index = index + 1;
		if (index % READ_SIZE == 0) {
			string[index] = '\0';
			string = my_realloc(string, (index + READ_SIZE + 2));
		}
	}
	string[index] = '\0';
	if (check_character(character, string))
		return (NULL);
	return (string);
}