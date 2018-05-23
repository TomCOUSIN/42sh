##
## EPITECH PROJECT, 2018
## 42sh
## File description:
## Makefile
##

SHELL=		bash

CC=		gcc -Ofast -o

RM=		rm -f

ALIAS_HANDLING	=		display_alias_content.c						\
				is_contain_quotes.c						\
				overwrite_alias.c						\
				add_alias_node.c						\
				is_alias_exist.c						\
				transform_cmd.c							\
				remove_quotes.c							\
				display_alias.c							\
				remove_alias.c							\
				free_alias.c							\
				init_alias.c							\
				add_alias.c

CD		=		find_env_variable.c						\
				change_directory.c						\
				go_to_target.c							\
				change_env.c							\
				go_home.c							\
				go_back.c

UNSETENV	=		remove_variable.c						\
				remove_env.c

SETENV		=		create_new_var_not_empty.c					\
				overwrite_var_not_empty.c					\
				create_new_var_empty.c						\
				find_variable_index.c						\
				overwrite_var_empty.c						\
				is_variable_exist.c						\
				create_new_var.c						\
				overwrite_var.c							\
				modify_env.c

BUILTIN		=		$(addprefix unsetenv/, $(UNSETENV))				\
				$(addprefix setenv/, $(SETENV))					\
				$(addprefix cd/, $(CD))						\
				find_builtin.c							\
				do_unsetenv.c							\
				do_setenv.c							\
				do_env.c							\
				echo/do_echo.c							\
				echo/parse_option.c						\
				do_cd.c

ENV_HANDLING=			copy_env.c							\
				find_env.c

LINE_EDITION=			get_char.c							\
				get_line.c

PARSING_SEPARATOR_HANDLING=	is_a_separator.c

PARSING_HANDLING=		$(addprefix separator_handling/, $(PARSING_SEPARATOR_HANDLING))	\
				put_first_separator.c						\
				my_put_separator.c						\
				my_put_in_list.c						\
				my_show_list.c							\
				create_list.c							\
				free_list.c

SHELL_EXECUTION_HANDLING=	signal_handler.c						\
				execute_list.c							\
				exe_binary.c							\
				exec_tools.c

SHELL_HANDLING=			$(addprefix execution_handling/, $(SHELL_EXECUTION_HANDLING))	\
				shell.c

SRC=				$(addprefix src/parsing_handling/, $(PARSING_HANDLING))		\
				$(addprefix src/shell_handling/, $(SHELL_HANDLING))		\
				$(addprefix src/alias_handling/, $(ALIAS_HANDLING))		\
				$(addprefix src/env_handling/, $(ENV_HANDLING))			\
				$(addprefix src/line_edition/, $(LINE_EDITION))			\
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
