/*
** EPITECH PROJECT, 2018
** my_strsplit.c
** File description:
** Split a string into an array of words each c character.
*/

#include <stdlib.h>
# include <string.h>
#include "my.h"

static int	count_words(char const *str, char c)
{
	int	words_count;
	int	index;

	index = 0;
	words_count = 1;
	while (str[index + 1] != '\0') {
		if (str[index] == c && str[index + 1] != c) {
			words_count = words_count + 1;
		}
		index = index + 1;
	}
	return (words_count);
}

static int	count_characters(char const *str, char c, int start)
{
	int	index;

	index = 0;
	while (str[start + index] != c && str[start + index] != '\0') {
		index = index + 1;
	}
	return (index);
}

static int	remove_charac(char const *str, char c, int index)
{
	while (str[index] == c && str[index] != '\0') {
		index = index + 1;
	}
	return (index);
}

char	**my_strsplit(char const *str, char c)
{
	char	**array;
	int	array_len;
	int	line_len;
	int	index_bis = 0;
	int	index = 0;

	array_len = count_words(str, c);
	array = malloc(sizeof(char *) * array_len + 8);
	if (array == NULL) {
		return (NULL);
	}
	while (index < array_len) {
		index_bis = remove_charac(str, c, index_bis);
		line_len = count_characters(str, c, index_bis);
		array[index] = strndup(&str[index_bis], line_len);
		index_bis = index_bis + line_len + 1;
		index = index + 1;
	}
	array[index] = NULL;
	return (array);
}
