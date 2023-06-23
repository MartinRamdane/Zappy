/*
** EPITECH PROJECT, 2023
** incantation.c
** File description:
** incantation
*/

#include "../include/server.h"

int check_can_incantation_3(client_t *client, tile *_tile)
{
    if (client->player->level == 6) {
        if (_tile->linemate >= 1 && _tile->deraumere >= 2 &&
        _tile->sibur >= 3 && _tile->phiras >= 1 &&
        get_nb_players_on_tile(_tile) >= 6) {
            return 1;
        }
    }
    if (client->player->level == 7) {
        if (_tile->linemate >= 2 && _tile->deraumere >= 2 &&
        _tile->sibur >= 2 && _tile->phiras >= 2 && _tile->mendiane >= 2 &&
        _tile->thystame >= 1 && get_nb_players_on_tile(_tile) >= 6) {
            return 1;
        }
    }
    return 0;
}

int check_can_incantation_2(client_t *client, tile *_tile)
{
    if (client->player->level == 4) {
        if (_tile->linemate >= 1 && _tile->deraumere >= 1 &&
        _tile->sibur >= 2 && _tile->phiras >= 1 &&
        get_nb_players_on_tile(_tile) >= 4) {
            return 1;
        }
    }
    if (client->player->level == 5) {
        if (_tile->linemate >= 1 && _tile->deraumere >= 2 &&
        _tile->sibur >= 1 && _tile->mendiane >= 3 &&
        get_nb_players_on_tile(_tile) >= 4) {
            return 1;
        }
    }
    return (check_can_incantation_3(client, _tile));
}

int check_can_incantation(server_t *server, client_t *client)
{
    int _x = client->player->x; int _y = client->player->y;
    tile *_tile = &server->game->map[_x][_y];
    if (client->player->level == 1) {
        if (_tile->linemate >= 1 && get_nb_players_on_tile(_tile) >= 1) {
            return 1;
        }
    }
    if (client->player->level == 2) {
        if (_tile->linemate >= 1 && _tile->deraumere >= 1 &&
        _tile->sibur >= 1 && get_nb_players_on_tile(_tile) >= 2) {
            return 1;
        }
    }
    if (client->player->level == 3) {
        if (_tile->linemate >= 2 && _tile->sibur >= 1 &&
        _tile->phiras >= 2 && get_nb_players_on_tile(_tile) >= 2) {
            return 1;
        }
    }
    return (check_can_incantation_2(client, _tile));
}