/*
** EPITECH PROJECT, 2018
** My_strncmp
** File description:
** my_strncmp
*/

int	my_strncmp(char const *str1, char const *str2, int index_max)
{
	int index = 0;

	if (!str1 || !str2 || index_max <= 0)
		return (1);
	while (str1[index] == str2[index] && index < index_max - 1) {
		index = index + 1;
	}
	return (str1[index] - str2[index]);
}