/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** remove all quotes from a string
*/

# include <stdlib.h>
# include <string.h>

static	int	count_quote(char *str)
{
	int	count = 0;
	int	index = 0;

	while (str[index] != '\0') {
		if (str[index] == '"') {
			count = count + 1;
		}
		index = index + 1;
	}
	return (count);
}

char	*remove_quotes(char *str)
{
	char	*copy = NULL;
	int	quote_count = count_quote(str);
	int	index_copy = 0;
	int	index_str = 0;

	copy = malloc(sizeof(char) * (strlen(str) - quote_count + 1));
	while (str[index_str] != '\0') {
		if (str[index_str] != '"') {
			copy[index_copy] = str[index_str];
			index_copy = index_copy + 1;
		}
		index_str = index_str + 1;
	}
	copy[index_copy] = '\0';
	return (copy);
}