/*
** EPITECH PROJECT, 2018
** MY_H_
** File description:
** MY_H_
*/

# ifndef	MY_H_
# define	MY_H_

/*
** previous include
*/
	# include <stdarg.h>

/*
** array/
*/
	char	**my_array_realloc(char **array, int index);
	char	**my_array_dup(char const **array);
	int	my_array_show(char const **array);
	int	my_array_len(char const **array);
	int	my_array_free(char **array);

/*
** str/
*/
	int	my_strncmp(char const *str1, char const *str2, int index_max);
	int	my_strcmp(char const *str1, char const *str2);
	char	**my_str_to_word_array(char *str);
	char	*my_strdup(char const *src);
	int	my_strlen(char const *src);
	char	*my_clean_str(char *str);

/*
** printf/
*/
	void	my_unsigned_put_nbr(unsigned int number);
	void	my_swap(char *str1, char *str2);
	void	my_put_nbr(int number);
	void	my_putchar(char c);
	char	*my_revstr(char*);
	int	my_compute_power_rec(int number, int power);
	int	my_printf(const char*, ...);
	int	percent_char(va_list);
	int	my_specialstr(char*);
	int	percent_xb(va_list);
	int	percent_sb(va_list);
	int	percent_d(va_list);
	int	percent_s(va_list);
	int	percent_i(va_list);
	int	percent_x(va_list);
	int	percent_u(va_list);
	int	percent_o(va_list);
	int	percent_b(va_list);
	int	my_putstr(char*);
	int	low_hexa(int);
	int	up_hexa(int);

/*
** get_next_line/
*/
	# ifndef	GET_NEXT_LINE_H_
	# define	GET_NEXT_LINE_H_

		# ifndef	READ_SIZE
		# define	READ_SIZE	(10)
		# endif		/* READ_SIZE */

	# endif		/* GET_NEXT_LINE */
	char	*get_next_line(const int fd);

/*
** alloc/
*/
	char	*my_realloc(char *str, int index);

# endif		/* MY_H_ */
