##
## EPITECH PROJECT, 2018
## 42sh
## File description:
## Makefile
##

SHELL=		bash

CC=		gcc -O3 -Ofast -o

RM=		rm -f

BUILTIN=			setenv/my_setenv.c	\
				setenv/setenv_error.c

ENV_HANDLING=			copy_env.c	\
				find_env.c

PARSING_SEPARATOR_HANDLING=	is_a_separator.c

PARSING_HANDLING=		$(addprefix separator_handling/, $(PARSING_SEPARATOR_HANDLING))	\
				my_put_separator.c						\
				my_put_in_list.c						\
				my_show_list.c							\
				create_list.c							\
				free_list.c

SHELL_EXECUTION_HANDLING=	signal_handler.c						\
				execute_list.c

SHELL_HANDLING=			$(addprefix execution_handling/, $(SHELL_EXECUTION_HANDLING))	\
				shell.c

SRC=				$(addprefix src/parsing_handling/, $(PARSING_HANDLING))		\
				$(addprefix src/shell_handling/, $(SHELL_HANDLING))		\
				$(addprefix src/env_handling/, $(ENV_HANDLING))			\
				$(addprefix src/builtin/, $(BUILTIN))				\
				src/main.c

OBJ=		$(SRC:.c=.o)

CFLAGS=		-Wall -Wextra
CFLAGS+=	-I./include

LDFLAGS=	-lncurses -L./lib/ -lmy

LPATH=		lib/

NAME=		42sh

DEBUG=		no

ifeq		($(DEBUG), yes)
CFLAGS+=	-g
else
CFLAGS+=	-Werror
endif

all:		$(NAME)

$(NAME):	$(OBJ)
		@make -C $(LPATH);
		@$(CC) $(NAME) $(OBJ) $(LDFLAGS)
		@echo -e "42sh Compilation [ DONE ]"

clean:
		@make -C $(LPATH) clean
		@$(RM) $(OBJ)

fclean:		clean
		@make -C $(LPATH) fclean
		@$(RM) $(NAME)

re:		fclean all

.c.o:
		@gcc -c -o $@ $< $(CFLAGS)

.PHONY:		re fclean clean all
