/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include "my.h"

static	int	my_custom_strlen(char *str, int index)
{
	int	count = 0;
	int	quote = 0;

	if (str[index] == '"') {
		quote = 1;
	}
	while ((quote || str[index] != ' ') && str[index + 1] != '\0') {
		index = index + 1;
		count = count + 1;
		if (str[index] == '"') {
			quote = 0;
		}
	}
	return (count);
}

static	char	*my_strndup(char *str, int *index)
{
	char	*string = NULL;
	int	quote = 0;
	int	i = 0;

	string = malloc(sizeof(char) * (my_custom_strlen(str, *index) + 2));
	if (string == NULL)
		return (NULL);
	if (str[*index] == '"')
			quote = 1;
	while ((quote || str[*index] != ' ') && str[*index] != '\0') {
		string[i] = str[*index];
		*index = *index + 1;
		i++;
		if (str[*index] == '"')
			quote = 0;
	}
	string[i] = '\0';
	*index = *index + 1;
	if (i == 0)
		return (NULL);
	return (string);
}

static	int	count_words(char *str)
{
	int	index = 0;
	int	count = 0;
	int	quote = 0;

	while (str && str[index] != '\0') {
		if (str[index] == '"') {
			quote += 1;
		}
		if (str[index] == ' ' && (quote % 2 == 0))
			count = count + 1;
		index = index + 1;
	}
	return (count + 1);
}

char	**my_str_to_word_array(char *string)
{
	char	**array = NULL;
	int	str_index = 0;
	int	nb_words = 0;
	int	index = 0;

	if (!string)
		return (NULL);
	nb_words = count_words(string);
	array = malloc(sizeof(char*) * (nb_words + 1));
	if (array == NULL) {
		return (NULL);
	}
	while (index < nb_words) {
		array[index] = my_strndup(string, &str_index);
		index = index + 1;
	}
	array[nb_words] = NULL;
	index = 0;
	return (array);
}
