/*
** EPITECH PROJECT, 2018
** Minishell
** File description:
** my_clean_str
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

static	int	remove_tab(char *str)
{
	int	index = 0;

	while (str[index] != '\0') {
		if (str[index] == '\t')
			str[index] = ' ';
		index = index + 1;
	}
	return (0);
}

static	char	*malloc_string(char *str)
{
	char	*clean_str = NULL;
	int	count = 0;
	int	index = 0;

	while (str[index] == ' ') {
		index = index + 1;
	}
	while (str[index] != '\0') {
		if ((str[index] == ' ' &&
		(str[index + 1] != ' ' && str[index + 1] != '\0')) ||
		(str[index] > ' ' && str[index] <= '~')) {
			count = count + 1;
		}
		index = index + 1;
	}
	clean_str = malloc(sizeof(char) * count + 1);
	if (clean_str == NULL)
		return (NULL);
	return (clean_str);
}

static	int	fill_string(char *str, char *clean_str)
{
	int	index_string = 0;
	int	index_str = 0;

	while (str[index_str] == ' ') {
		index_str = index_str + 1;
	}
	while (str[index_str] != '\0') {
		if ((str[index_str] == ' ' &&
		(str[index_str + 1] != ' ' && str[index_str + 1] != '\0')) ||
		(str[index_str] > ' ' && str[index_str] <= '~')) {
			clean_str[index_string] = str[index_str];
			index_string = index_string + 1;
		}
		index_str = index_str + 1;
	}
	clean_str[index_string] = '\0';
	return (0);
}

char	*my_clean_str(char *str)
{
	char	*clean_str = NULL;

	if (!str)
		return (NULL);
	remove_tab(str);
	clean_str = malloc_string(str);
	if (clean_str == NULL)
		return (NULL);
	fill_string(str, clean_str);
	free(str);
	return (clean_str);
}