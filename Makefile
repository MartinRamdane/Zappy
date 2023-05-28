##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

.PHONY: all clean

# Default target

SERVER_NAME = zappy_server
CLIENT_NAME = zappy_gui
AI_NAME = zappy_ai

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
END_COLOR=\033[0m

all: compile

# Build target
compile: z_server z_gui z_ai

z_server:
	cd server && make
	mv server/$(SERVER_NAME) .
	@echo "$(COLOUR_GREEN)Server build$(END_COLOR)"

z_gui:
	@echo "$(COLOUR_RED)gui: Add make command in main makefile$(END_COLOR)"

z_ai:
	cp ai/main.py ./
	mv main.py $(AI_NAME)
	chmod +x $(AI_NAME)
	@echo "$(COLOUR_GREEN)AI build$(COLOUR_GREEN)"

# Clean target
clean:
	@rm -f *~ | rm -f *.o
	@echo "$(COLOUR_GREEN)Clean done.$(END_COLOR)"

fclean: clean
		@rm -f $(CLIENT_NAME) | rm -f $(SERVER_NAME) | rm -f $(AI_NAME)
		@echo "$(COLOUR_GREEN)All binaries are cleaned.$(END_COLOR)"

re:
	make clean
	make