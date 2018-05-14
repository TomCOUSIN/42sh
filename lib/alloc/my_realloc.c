/*
** EPITECH PROJECT, 2018
** My_realloc
** File description:
** my_realloc
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

static	int	fill_str(char *str, char *copy)
{
	int index = 0;

	while (copy[index] != '\0') {
		str[index] = copy[index];
		index = index + 1;
	}
	return (0);
}

static	int	fill_copy(char *copy, char *str)
{
	int index = 0;

	while (str[index] != '\0') {
		copy[index] = str[index];
		index = index + 1;
	}
	copy[index] = '\0';
	return (0);
}

char	*my_realloc(char *str, int index)
{
	char	*new_str = NULL;
	char	*copy = NULL;
	int	len = 0;

	len = my_strlen(str);
	copy = malloc(sizeof(char) * len + 1);
	fill_copy(copy, str);
	free(str);
	new_str = malloc(sizeof(char) * index + 1);
	fill_str(new_str, copy);
	free(copy);
	new_str[index] = '\0';
	return (new_str);
}