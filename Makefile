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

compile_gui = cd gui && make

ifeq ($(shell uname -s),Darwin)
	compile_gui = $(shell cd gui && mkdir build && cd build && cmake .. && cmake --build .)
endif

compile_server = cd server && make
ifeq ($(shell uname -s),Darwin)
	compile_server = $(shell cd server && mkdir build && cd build && cmake .. && cmake --build .)
endif

all: compile

# Build target
compile: z_server z_gui z_ai

z_server:
	$(compile_server)
	mv server/$(SERVER_NAME) .
	@echo "$(COLOUR_GREEN)Server build$(END_COLOR)"
\
z_gui:
	$(compile_gui)
	mv gui/$(CLIENT_NAME) .
	@echo "$(COLOUR_GREEN)Gui build$(COLOUR_GREEN)"

z_ai:
	echo "#/bin/bash" > zappy_ai
	echo 'python3 ai/main.py $$1 $$2 $$3 $$4 $$5 $$6' >> zappy_ai
	chmod +x zappy_ai
	@echo "$(COLOUR_GREEN)AI build$(COLOUR_GREEN)"

# Clean target
clean:
	@rm -f *~ | rm -f *.o
	@rm -rf gui/build
	@rm -rf server/build
  
	@echo "$(COLOUR_GREEN)Clean done.$(END_COLOR)"

fclean: clean
		@rm -f $(CLIENT_NAME) | rm -f $(SERVER_NAME) | rm -f $(AI_NAME)
		@echo "$(COLOUR_GREEN)All binaries are cleaned.$(END_COLOR)"

re:
	make clean
	make
