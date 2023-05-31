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

void debug_print_gui_player(client_t *cli)
{
    if (!cli->gui_player) {
        printf("Error: no gui player for this client\n");
        return;
    }
    printf("[DEBUG] client socket: %d | x: %d y: %d\n",
    cli->socket, cli->gui_player->x, cli->gui_player->y);
}

void debug_print_player(client_t *cli)
{
    if (!cli->player) {
        printf("Error: no player for this client\n");
        return;
    }
    printf("[DEBUG] client socket: %d | x: %d y: %d level: %d is_dead: %d ",
    cli->socket, cli->player->x, cli->player->y, cli->player->level,
    cli->player->is_dead);
    printf("orientation: %c team name: %s\n",
    cli->player->orientation, cli->player->team_name);
}