/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Builtin header
*/

# ifndef	__BUILTIN_H_
# define	__BUILTIN_H_

int	my_setenv(char **argv, char **env);
int	setenv_error(char **argv, char **env);

/*
** Setenv error msg
**/
	# define	TOO_MANY_ARG		\
		"setenv: Too many arguments.\n"
	# define	BAD_FIRST_DIGIT	\
		"setenv: Variable name must begin with a letter.\n"
	# define	NOT_ALPHANUMERIC	\
		"setenv: Variable name must contain alphanumeric characters.\n"

# endif // __BUILTIN_H_
