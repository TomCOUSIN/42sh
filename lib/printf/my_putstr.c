/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** task02
*/

# include "unistd.h"

void	my_putchar(char c);

int	my_putstr(char const *str)
{
	char	*null = "(null)";
	int i = 0;

	if (str == NULL) {
		while (null[i] != '\0') {
			my_putchar(null[i]);
			i = i + 1;
		}
	}
	else {
		while (str[i] != '\0' ) {
			my_putchar(str[i]);
			i = i + 1;
		}
	}
	return (0);
}
