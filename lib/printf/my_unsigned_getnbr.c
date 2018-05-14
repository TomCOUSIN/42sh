/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** my_getnbr
*/

#include "my.h"

unsigned int	my_unsigned_getnbr(char const *str)
{
	int i = 0;
	unsigned int nbr = 0;
	int signe = 0;

	while (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-') {
			signe = signe + 1.;
			i = i + 1;
		}
		while (str[i] >= '0' && str[i] <= '9') {
			nbr = nbr * 10 + (str[i] - 48);
			i = i + 1;
		}
		if (signe % 2 != 0)
			return (-nbr);
	}
	return (nbr);
}
