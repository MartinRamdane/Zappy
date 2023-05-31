/*
** EPITECH PROJECT, 2023
** map_change.c
** File description:
** map_change
*/

#include "../include/server.h"

void move_player(player *p, tile **map, int x, int y)
{
    map[p->x][p->y].player = NULL;
    p->x = x;
    p->y = y;
    map[x][y].player = p;
}
