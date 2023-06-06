##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

NAME = zappy_server

SRC = src/*.c

FLAGS = -Wall -Wextra -g3 -lm -luuid

all:
	gcc -o $(NAME) $(SRC) $(FLAGS)

clean:
	rm -f *~ | rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all
