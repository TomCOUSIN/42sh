/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** initialization of the shell
*/

# include <stdlib.h>
# include "sh.h"

shell_t	*init_shell(void)
{
	shell_t	*shell = NULL;

	shell = malloc(sizeof(*shell));
	shell->alias = init_alias();
	shell->cmd = NULL;
	return (shell);
}