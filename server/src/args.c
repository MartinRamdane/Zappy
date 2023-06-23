/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane [WSL: Ubuntu]
** File description:
** args
*/

#include "../include/server.h"

server_t *create_server_struct(void)
{
    server_t *s_infos = malloc(sizeof(server_t));
    s_infos->port = -1;
    s_infos->width = -1;
    s_infos->height = -1;
    s_infos->sname = malloc(sizeof(char *) * 100);
    s_infos->clientsNb = -1;
    s_infos->freq = -1;
    s_infos->player_id = 0; s_infos->egg_id = 0;
    s_infos->game = malloc(sizeof(game_t));
    memset(s_infos->sname, 0, 100);
    return (s_infos);
}

void check_args(server_t *s_infos)
{
    if (s_infos->port == -1 || s_infos->width == -1 || s_infos->height == -1
    || s_infos->sname == NULL || s_infos->clientsNb == -1
    || s_infos->freq == -1 || my_arrlen(s_infos->sname) <= 0) {
        printf("Error: missing argument\n");
        print_help();
        exit(84);
    }
}
