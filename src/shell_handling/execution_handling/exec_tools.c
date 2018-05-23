/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** execution tools
*/

#include <stdlib.h>
#include "my.h"

char *my_strcpy(char *str)
{
	char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
	int index = 0;

	if (new_str == NULL)
		return (NULL);
	while (str[index] != '\0') {
		new_str[index] = str[index];
		++index;
	}
	new_str[index] = '\0';
	return (new_str);
}

char *my_cat_path(char *dest, char *ori)
{
	char *ret = malloc(sizeof(char *) * (my_strlen(dest) + my_strlen(ori)
					+ 2));
	char *tmp_ret = ret;
	char *tmp_ori = ori;

	if (!ret)
		return (NULL);
	while (dest && *dest) {
		*tmp_ret = *dest;
		++dest;
		++tmp_ret;
	}
	*tmp_ret++ = '/';
	while (tmp_ori && *tmp_ori) {
		*tmp_ret = *tmp_ori;
		++tmp_ret;
		++tmp_ori;
	}
	free(ori);
	*tmp_ret = '\0';
	return(ret);
}
