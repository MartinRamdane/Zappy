/*
** EPITECH PROJECT, 2023
** map_change.c
** File description:
** map_change
*/

#include "../include/server.h"

void move_player(player *p, tile **map, int *pos, server_t *s_infos)
{
    int new_x = pos[0], new_y = pos[1];
    if (!map[p->x + 1])
        new_x = 0;
    if (!map[p->x - 1])
        new_x = s_infos->width - 1;
    if (!map[p->y + 1])
        new_y = 0;
    if (!map[p->y - 1])
        new_y = s_infos->height - 1;
    map[p->x][p->y].player = NULL;
    p->x = new_x;
    p->y = new_y;
    map[new_x][new_y].player = p;
}
