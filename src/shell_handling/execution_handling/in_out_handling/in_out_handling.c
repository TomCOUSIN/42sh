/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** input_output
*/

#include "redirect.h"
#include "my.h"

static const char *tab_separator[] =
{
	"|",
	"<",
	"<<",
	">",
	">>"
};

static int (*fptr_tab[])(int **io, list_t *separator) = {
	&my_pipe,
	&simple_left,
	&double_left,
	&simple_right,
	&double_right
};

int init_pipe(list_t *separator)
{
	int index = 0;
	list_t *next_link = separator->next[SEPARATOR];
	int ret = 0;

	while (index < 5) {
		if (my_strcmp(separator->cmd[0], tab_separator[index]) == 0) {
			ret = fptr_tab[index]
				((int **) &(separator->pipe), next_link);
			return(ret);
		}
		++index;
	}
	return(0);
}
