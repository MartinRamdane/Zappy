/*
** EPITECH PROJECT, 2023
** update_incantation.c
** File description:
** update_incantation
*/

#include "../include/server.h"

void update_incantation_3(client_t *client, tile *_tile, server_t *server)
{
    if (client->player->level == 6) {
        _tile->linemate -= 1; _tile->deraumere -= 2;
        _tile->sibur -= 3; _tile->phiras -= 1;
    }
    if (client->player->level == 7) {
        _tile->linemate -= 2; _tile->deraumere -= 2;
        _tile->sibur -= 2; _tile->phiras -= 2;
        _tile->mendiane -= 2; _tile->thystame -= 1;
    }
    send_map_content_to_all_gui(server);
}

void update_incantation_2(client_t *client, tile *_tile, server_t *server)
{
    if (client->player->level == 4) {
        _tile->linemate -= 1; _tile->deraumere -= 1;
        _tile->sibur -= 2; _tile->phiras -= 1;
    }
    if (client->player->level == 5) {
        _tile->linemate -= 1; _tile->deraumere -= 2;
        _tile->sibur -= 1; _tile->mendiane -= 3;
    }
    update_incantation_3(client, _tile, server);
}

void update_incantation(server_t *server, client_t *client)
{
    int _x = client->player->x; int _y = client->player->y;
    tile *_tile = &server->game->map[_x][_y];
    if (client->player->level == 1) {
        _tile->linemate -= 1;
    }
    if (client->player->level == 2) {
        _tile->linemate -= 1; _tile->deraumere -= 1; _tile->sibur -= 1;
    }
    if (client->player->level == 3) {
        _tile->linemate -= 2; _tile->sibur -= 1; _tile->phiras -= 2;
    }
    update_incantation_2(client, _tile, server);
}