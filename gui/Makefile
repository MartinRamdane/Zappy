##
## EPITECH PROJECT, 2023
## GUI
## File description:
## Makefile
##

SRC = src/*.cpp \
	src/socket/*.cpp \
	src/GUI/*.cpp \

NAME = zappy_gui

all:
	g++ -o $(NAME) $(SRC) -g3

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re:	fclean all
