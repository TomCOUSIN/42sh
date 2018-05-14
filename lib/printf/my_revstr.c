/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** task03
*/

#include "my.h"

char	*my_revstr(char *str)
{
	int i = 0;
	int nbr_letter = my_strlen(str) - 1;

	while (i < nbr_letter) {
		my_swap(&str[i], &str[nbr_letter]);
		nbr_letter--;
		i++;
	}
	return (str);
}
