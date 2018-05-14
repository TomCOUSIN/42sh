/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** my_put_nbr
*/

#include <unistd.h>
#include "my.h"

void	my_unsigned_put_nbr(unsigned int number)
{
	unsigned int zero = 0;
	unsigned int nine = 9;

	if (number > nine) {
		my_unsigned_put_nbr(number / 10);
	}
	else if (number < zero) {
		number = number * -1;
		my_putchar('-');
		my_unsigned_put_nbr(number / 10);
	}
	my_putchar(number % 10 + 48);
}
