##
## EPITECH PROJECT, 2019
## minishell1
## File description:
## makefile ok mysh
##

SRC	=	src/main.c	\
		src/get_path.c	\
		src/fonction.c

OBJ	 =	   $(SRC:.c=.o)

CFLAGS  =	-Wall		\
		-Wextra		\
		-I./include	\

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *#

fclean:	clean
		rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur
