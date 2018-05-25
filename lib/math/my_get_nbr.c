/*
** EPITECH PROJECT, 2018
** my_get_nbr.c
** File description:
** my_get_nbr.c
*/

int	my_get_nbr(char *str)
{
	int	nb = 0;
	int	index = 0;

	while (str[index] != '\0' && (str[index] < '0' || str[index] > '9')) {
		index = index + 1;
	}
	while (str[index] >= '0' && str[index] <= '9') {
		nb = nb * 10;
		nb = nb + str[index] - '0';
		index = index + 1;
	}
	return (nb);
}
