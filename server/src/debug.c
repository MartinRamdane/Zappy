/*
** EPITECH PROJECT, 2023
** debug.c
** File description:
** debug
*/

#include "../include/server.h"

void debug_print_map(server_t *s_infos, tile **map)
{
    for (int x = 0; x < s_infos->width; x++) {
        for (int y = 0; y < s_infos->height; y++) {
            printf("x: %d, y: %d, %d %d %d %d %d %d %d\n",
            map[x][y].x, map[x][y].y, map[x][y].food, map[x][y].linemate,
            map[x][y].deraumere, map[x][y].sibur, map[x][y].mendiane,
            map[x][y].phiras, map[x][y].thystame);
        }
    }
}