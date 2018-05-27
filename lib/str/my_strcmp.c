/*
** EPITECH PROJECT, 2018
** My_strcmp
** File description:
** my_strcmp
*/

#include "my.h"

int	my_strcmp(char const *str1, char const *str2)
{
	int index = 0;

	if (!str1 || !str2)
		return (1);
	while (str1[index] == str2[index] && str1[index] != '\0') {
		index = index + 1;
	}
	return (str1[index] - str2[index]);
}
