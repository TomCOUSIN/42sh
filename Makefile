##
## EPITECH PROJECT, 2018
## 42sh
## File description:
## Makefile
##

SHELL=		bash

CC=		gcc -O3 -Ofast -o

RM=		rm -f

SRC=		src/main.c

OBJ=		$(SRC:.c=.o)

CFLAGS=		-Wall -Wextra
CFLAGS+=	-I./include

NAME=		42sh

DEBUG=		no

ifeq		($(DEBUG), yes)
CFLAGS+=	-g
else
CFLAGS+=	-Werror
endif

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		re fclean clean all