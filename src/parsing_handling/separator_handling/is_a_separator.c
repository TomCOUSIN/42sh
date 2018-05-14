/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** check if the character is a separator
*/

int	is_a_separator(char c)
{
	if (c == '>' || c == '<' || c == '|' || c == '&') {
		return (1);
	}
	return (0);
}