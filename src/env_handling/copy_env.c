/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** copy the environment or create one
*/

# include <stdlib.h>
# include "my.h"

static	char	**create_env(void)
{
	char	**env = NULL;

	env = malloc(sizeof(char *) * 2);
	if (env == NULL) {
		return (NULL);
	}
	else {
		env[0] =
		my_strdup("PATH=/bin:/usr/local/bin:/sbin:/usr/bin:/usr/sbin");
		env[1] = NULL;
	}
	return (env);
}

char	**copy_env(char **envp)
{
	char	**copy = NULL;

	if (envp) {
		copy = my_array_dup((char const **)envp);
	}
	else {
		copy = create_env();
	}
	return (copy);
}