/*
** EPITECH PROJECT, 2017
** My_strdup
** File description:
** my_strdup
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char	*my_strdup(char const *src)
{
	char	*str = NULL;
	int	index = 0;
	int	len = 0;

	len = my_strlen(src);
	if (len == 0)
		return (NULL);
	str = malloc(sizeof(char) * (len + 1));
	while (src[index] != '\0') {
		str[index] = src[index];
		index = index + 1;
	}
	str[index] = '\0';
	return (str);
}
