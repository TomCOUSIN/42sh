/*
** EPITECH PROJECT, 2017
** my_compute_power_rec
** File description:
** task04
*/

#include "my.h"

int	my_compute_power_rec(int nb, int p)
{
	int a = nb;

	if (p == 0)
		a = 1;
	else if (p < 0)
		a = 0;
	else
		a = nb * my_compute_power_rec(a, p - 1);
	return (a);
}
