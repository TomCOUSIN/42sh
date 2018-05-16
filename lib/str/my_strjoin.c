/*
** EPITECH PROJECT, 2018
** my_strjoin
** File description:
** Concatenate two strings
*/

# include <stdlib.h>
# include <string.h>

char	*my_strjoin(char const *str1, char const *str2)
{
	char	*str = NULL;
	int	len = 0;

	len = strlen(str1) + strlen(str2);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL) {
		return (NULL);
	}
	strcpy(str, str1);
	strcat(str, str2);
	return (str);
}
