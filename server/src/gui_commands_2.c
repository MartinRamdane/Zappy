/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane [WSL: Ubuntu]
** File description:
** gui_commands_2
*/

#include "../include/server.h"

void send_map_content(client_t *client, server_t *server)
{
    for (int i = 0; i != server->width; i++) {
        for (int j = 0; j != server->height; j++) {
            send_tile_with_pos(client, server, i, j);
        }
    }
}

void send_tile_with_pos(client_t *client, server_t *server, int x, int y)
{
    char *buffer = malloc(sizeof(char) * 100);
    memset(buffer, 0, 100);
    tile val = server->game->map[x][y];
    sprintf(buffer, "bct %d %d %d %d %d %d %d %d %d\n", x, y, val.food,
    val.linemate, val.deraumere, val.sibur, val.mendiane,
    val.phiras, val.thystame);
    send(client->socket, buffer, strlen(buffer), 0);
    free(buffer);
    return;
}

void send_new_player_connected(server_t *server, client_t *player)
{
    client_t *tmp = NULL;
    LIST_FOREACH(tmp, &server->head, next) {
        if (tmp->gui_player != NULL) {
            send_playerdata_to_gui(tmp, player);
            send_map_content(tmp, server);
        }
    }
}

void send_playerdata_to_gui(client_t *cli, client_t *pl)
{
    char *buffer = malloc(sizeof(char) * 100);
    memset(buffer, 0, 100);
    sprintf(buffer, "pnw %d %d %d %d %d %s\n", pl->player->id, pl->player->x,
    pl->player->y, orientation_to_number(pl->player->orientation),
    pl->player->level, pl->team_name);
    send(cli->socket, buffer, strlen(buffer), 0);
    free(buffer);
}
