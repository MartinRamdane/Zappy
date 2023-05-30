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

void fetch_arguments(server_t *s_infos, char **av)
{
    int i = 0, j = 0, n = 0; s_infos->sname = malloc(sizeof(char *) * 100);
    while (av[i]) {
        if (strcmp(av[i], "-p") == 0) {
            s_infos->port = atoi(av[i + 1]); n = 0;
        } if (strcmp(av[i], "-x") == 0) {
            s_infos->width = atoi(av[i + 1]); n = 0;
        } if (strcmp(av[i], "-y") == 0) {
            s_infos->height = atoi(av[i + 1]); n = 0;
        } if (strcmp(av[i], "-c") == 0) {
            s_infos->clientsNb = atoi(av[i + 1]); n = 0;
        } if (strcmp(av[i], "-f") == 0) {
            s_infos->freq = atoi(av[i + 1]); n = 0;
        } if (strcmp(av[i], "-n") == 0 || (n == 1 && av[i + 1]
            && av[i + 1][0] != '-')) {
            n = 1; s_infos->sname[j] = malloc(sizeof(char) * 100);
            strcpy(s_infos->sname[j], av[i + 1]); j++;
        }
        i++;
    }
}

int main(int ac, char **av) {
    if (ac == 1)
        return 0;
    if (strcmp(av[1], "-help") == 0 || strcmp(av[1], "-h") == 0) {
        print_help(); return 0;
    }
    server_t *s_infos = malloc(sizeof(server_t));
    fetch_arguments(s_infos, av);
    // printf("port: %d\n", s_infos->port);
    // printf("width: %d\n", s_infos->width);
    // printf("height: %d\n", s_infos->height);
    // printf("name: %s\n", s_infos->sname[0]);
    // printf("name: %s\n", s_infos->sname[1]);
    // printf("name: %s\n", s_infos->sname[2]);
    // printf("clientsNb: %d\n", s_infos->clientsNb);
    // printf("freq: %d\n", s_infos->freq);
    return 0;
}
