/*
** EPITECH PROJECT, 2023
** map_misc.c
** File description:
** map_misc
*/

#include "../include/server.h"

int *get_resources_quantities(int *ratio, server_t infos)
{
    int *q = malloc(sizeof(int) * 7);
    q[0] = ratio[0] / (infos.width * infos.height);
    q[1] = ratio[1] / (infos.width * infos.height);
    q[2] = ratio[2] / (infos.width * infos.height);
    q[3] = ratio[3] / (infos.width * infos.height);
    q[4] = ratio[4] / (infos.width * infos.height);
    q[5] = ratio[5] / (infos.width * infos.height);
    q[6] = ratio[6] / (infos.width * infos.height);
    return q;
}

int *get_remaining_resources(int *ratio, server_t infos)
{
    int *q = malloc(sizeof(int) * 7);
    q[0] = ratio[0] % (infos.width * infos.height);
    q[1] = ratio[1] % (infos.width * infos.height);
    q[2] = ratio[2] % (infos.width * infos.height);
    q[3] = ratio[3] % (infos.width * infos.height);
    q[4] = ratio[4] % (infos.width * infos.height);
    q[5] = ratio[5] % (infos.width * infos.height);
    q[6] = ratio[6] % (infos.width * infos.height);
    return q;
}

void put_phiras_resource(server_t infos, tile **map, int r)
{
    for (int i = 0; i < r; i++) {
        int x = rand() % infos.width;
        int y = rand() % infos.height;
        map[x][y].phiras++;
    }
}

void put_thystame_resource(server_t infos, tile **map, int r)
{
    for (int i = 0; i < r; i++) {
        int x = rand() % infos.width;
        int y = rand() % infos.height;
        map[x][y].thystame++;
    }
}

int get_nb_players_on_tile(tile *tile)
{
    t_player_queue *tmp = NULL;
    int i = 0;
    LIST_FOREACH(tmp, &tile->player_head, next) {
        i++;
    }
    return i;
}