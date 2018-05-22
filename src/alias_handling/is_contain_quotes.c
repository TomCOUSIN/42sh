/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** check if a string contains quotes
*/

int	is_contain_quotes(char *str)
{
	int	index = 0;

	while (str[index] != '\0') {
		if (str[index] == '"') {
			return (1);
		}
		index = index + 1;
	}
	return (0);
}