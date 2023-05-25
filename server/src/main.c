/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "../include/server.h"

void print_help() {
    printf("USAGE: ./zappy_server -p port -x width -y height -n name1 name2 ");
    printf("... -c clientsNb -f freq\n");
    printf("        port        is the port number\n");
    printf("        width       is the width of the world\n");
    printf("        height      is the height of the world\n");
    printf("        nameX       is the name of the team X\n");
    printf("        clientsNb   is the number of authorized clients per team");
    printf("\n        freq        is the reciprocal of");
    printf(" time unit for execution of actions\n");
}

int main(int ac, char **av) {
    if (strcmp(av[1], "-help") == 0 || strcmp(av[1], "-h") == 0) {
        print_help();
    }
}
