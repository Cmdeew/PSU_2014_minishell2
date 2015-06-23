##
## Makefile for minishell1 in /home/rieux-_t/Documents/rendu/Unix/PSU_2014_minishell1
## 
## Made by thomas rieux-laucat
## Login   <rieux-_t@epitech.net>
## 
## Started on  Mon Jan 26 12:02:11 2015 thomas rieux-laucat
## Last update Sun Mar 15 21:41:45 2015 Thomas Rieux-Laucat
##

SRC	=	base_fonction.c \
		my_strcpy.c \
		my_strdup.c \
		path.c \
		my_strcmp.c \
		my_strncmp.c \
		my_strcat.c \
		my_str_to_word_tab.c \
		my_show_tab.c \
		cmd.c \
		check_builtin.c \
		my_builtin.c \
		pars.c \
		my_wait.c

CC	=	gcc

RM	=	rm -rf

CFLAGS	+=	-W -Wall -Wextra

CFLAGS	+=	-pedantic -ansi -g3

NAME	=	mysh

OBJS	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
