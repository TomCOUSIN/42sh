/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** my_printf_function
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int	check_arg(va_list ap, char arg)
{
	char *arglist = "doixXubsSc%";
	int (*fptr[])(va_list) = {percent_d, percent_o,
				percent_i, percent_x,
				percent_xb, percent_u,
				percent_b, percent_s,
				percent_sb, percent_char};
	int i = 0;

	if (arg == '%') {
		my_putchar('%');
	} else {
		while (arglist[i] != '\0') {
			if (arglist[i] == arg)
				fptr[i](ap);
			i++;
		}
	}
	return (0);
}

int	my_printf(const char *format, ...)
{
	int i = 0;
	va_list ap;

	va_start(ap, format);
	while (format[i] != '\0') {
		if (format[i] == '%') {
			check_arg(ap, format[i + 1]);
			i += 2;
		} else {
			my_putchar(format[i++]);
		}
	}
	va_end(ap);
	return (0);
}
