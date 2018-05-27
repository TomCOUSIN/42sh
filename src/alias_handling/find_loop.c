/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** find if the alias is a loop
*/

# include <string.h>
# include "alias.h"
# include "sh.h"
# include "my.h"

static	int	my_array_cmp(char **array1, char **array2)
{
	int	index = 0;

	if (my_array_len((char const **)array1) !=
	my_array_len((char const **)array2))
		return (1);
	while (array1[index] != NULL) {
		if (strcmp(array1[index], array2[index]) != 0) {
			return (1);
		}
		index = index + 1;
	}
	return (0);
}

static	int	free_and_leave(char **alias_1, int count)
{
	if (count == 50) {
		my_array_free(alias_1);
		return (1);
	}
	my_array_free(alias_1);
	return (0);
}

int	find_loop(shell_t *shell, char *save)
{
	alias_t	*tmp = shell->alias;
	char	**alias_1 = NULL;
	char	**alias_2 = NULL;
	int	count = 0;

	alias_1 = my_str_to_word_array(save);
	while (tmp && count != 50) {
		alias_2 = my_str_to_word_array(tmp->alias);
		if (my_array_cmp(alias_1, alias_2) == 0) {
			my_array_free(alias_1);
			alias_1 = my_array_dup((char const **)tmp->cmd);
			tmp = shell->alias;
			count += 1;
		} else {
			tmp = tmp->next;
		}
		my_array_free(alias_2);
	}
	return (free_and_leave(alias_1, count));
}