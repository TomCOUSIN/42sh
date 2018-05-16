/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** main function for 42sh
*/

# include <unistd.h>
# include "env.h"
# include "sh.h"
# include "my.h"

int	main(int argc, char **argv, char **envp)
{
	int	status = 0;
	char	**env = NULL;

	if (argc != 1 && argv[1] != NULL) {
		return (84);
	}
	env = copy_env(envp);
	if (env == NULL) {
		return (84);
	}
	status = shell(env);
	my_array_free(env);
	return (status);
}
