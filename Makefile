##
## EPITECH PROJECT, 2018
## 42sh
## File description:
## Makefile
##

SHELL=		bash

CC=		gcc -O3 -Ofast -o

RM=		rm -f

ENV_HANDLING=	copy_env.c

SHELL_HANDLING=	shell.c

SRC=		$(addprefix src/shell_handling/, $(SHELL_HANDLING))	\
		$(addprefix src/env_handling/, $(ENV_HANDLING))		\
		src/main.c

OBJ=		$(SRC:.c=.o)

CFLAGS=		-Wall -Wextra
CFLAGS+=	-I./include

LDFLAGS=	-L./lib/ -lmy

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