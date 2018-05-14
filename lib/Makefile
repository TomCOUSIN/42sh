##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for lib
##

RM	=	rm -f

GNL	=	get_next_line.c

ALLOC	=	my_realloc.c

PRINTF	=	my_printf.c			\
		my_putchar.c			\
		my_putstr.c			\
		my_put_nbr.c			\
		my_compute_power_rec.c		\
		my_swap.c			\
		my_revstr.c			\
		low_hexa.c			\
		up_hexa.c			\
		my_specialstr.c			\
		my_unsigned_put_nbr.c		\
		basic_percent.c			\
		special_percent.c

ARRAY	=	my_array_realloc.c		\
		my_array_free.c			\
		my_array_show.c			\
		my_array_dup.c			\
		my_array_len.c

STR	=	my_str_to_word_array.c		\
		my_clean_str.c			\
		my_strncmp.c			\
		my_strdup.c			\
		my_strcmp.c			\
		my_strlen.c

SRC	=	$(addprefix get_next_line/, $(GNL))	\
		$(addprefix printf/, $(PRINTF))		\
		$(addprefix array/, $(ARRAY))		\
		$(addprefix alloc/, $(ALLOC))		\
		$(addprefix str/, $(STR))

CFLAGS	=	-Wall -Wextra -I./include/

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
		@ar rc $(NAME) $(OBJ)
		@cp ./include/my.h ../include/

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.c.o:
		@gcc -c -o $@ $< $(CFLAGS)

.PHONY:		re fclean all clean
