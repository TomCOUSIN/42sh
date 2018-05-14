/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** my_put_nbr
*/

#include <unistd.h>

void	my_putchar(char c);

void	my_put_nbr(int number)
{
	if (number > 9) {
		my_put_nbr(number / 10);
	}
	else if (number < 0) {
		number = number * -1;
		my_putchar('-');
		my_put_nbr(number / 10);
	}
	my_putchar(number % 10 + 48);
}
