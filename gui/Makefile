##
## EPITECH PROJECT, 2023
## GUI
## File description:
## Makefile
##

SRC = src/*.cpp

NAME = zappy_gui

all:
	g++ -o $(NAME) $(SRC) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re:	fclean all
