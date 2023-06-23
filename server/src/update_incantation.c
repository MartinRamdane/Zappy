/*
** EPITECH PROJECT, 2023
** update_incantation.c
** File description:
** update_incantation
*/

#include "../include/server.h"

int has_incantating_players_on_tile(tile *tile)
{
    t_player_queue *tmp = NULL;
    LIST_FOREACH(tmp, &tile->player_head, next) {
        if (tmp->player->state == INCANTATION)
            return 1;
    }
    return 0;
}

void update_incantation_3(client_t *client, tile *_tile, server_t *server)
{
    int level = client->player->level - 1;
    if (level ==  6 && has_incantating_players_on_tile(_tile) == 0) {
        _tile->linemate -= 1; _tile->deraumere -= 2;
        _tile->sibur -= 3; _tile->phiras -= 1;
    }
    if (level == 7 && has_incantating_players_on_tile(_tile) == 0) {
        _tile->linemate -= 2; _tile->deraumere -= 2;
        _tile->sibur -= 2; _tile->phiras -= 2;
        _tile->mendiane -= 2; _tile->thystame -= 1;
    }
    send_map_content_to_all_gui(server);
}

void update_incantation_2(client_t *client, tile *_tile, server_t *server)
{
    int level = client->player->level - 1;
    if (level == 4 && has_incantating_players_on_tile(_tile) == 0) {
        _tile->linemate -= 1; _tile->deraumere -= 1;
        _tile->sibur -= 2; _tile->phiras -= 1;
    }
    if (level == 5 && has_incantating_players_on_tile(_tile) == 0) {
        _tile->linemate -= 1; _tile->deraumere -= 2;
        _tile->sibur -= 1; _tile->mendiane -= 3;
    }
    update_incantation_3(client, _tile, server);
}

void update_incantation(server_t *server, client_t *client)
{
    int _x = client->player->x; int _y = client->player->y;
    tile *_tile = &server->game->map[_x][_y];
    int level = client->player->level - 1;
    if (level == 1) {
        _tile->linemate -= 1;
    }
    if (level == 2 && has_incantating_players_on_tile(_tile) == 0) {
        _tile->linemate -= 1; _tile->deraumere -= 1; _tile->sibur -= 1;
    }
    if (level == 3 && has_incantating_players_on_tile(_tile) == 0) {
        _tile->linemate -= 2; _tile->sibur -= 1; _tile->phiras -= 2;
    }
    update_incantation_2(client, _tile, server);
}