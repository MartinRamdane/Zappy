/*
** EPITECH PROJECT, 2023
** eject.c
** File description:
** eject
*/

#include "../include/server.h"

void eject_all_players(server_t *server, client_t *client, int x, int y)
{
    int _x = client->player->x; int _y = client->player->y;
    t_player_queue *tmp = NULL;
    LIST_FOREACH(tmp, &server->game->map[_x][_y].player_head, next) {
        if (strcmp(tmp->player->uid, client->uid) != 0) {
            tmp->player->x = x; tmp->player->y = y;
            add_player_from_queue(&server->game->map[x][y], tmp->player);
            remove_player_from_queue(&server->game->map[_x][_y], tmp->player);
        }
    }
}

int eject_player(server_t *server, client_t *client)
{
    int _x = client->player->x; int _y = client->player->y;
    if (check_if_solo_on_tile(server, client) == 0)
        return 0;
    if (client->player->orientation == 'N')
        _y = get_case(server, client->player->orientation, _y, 1);
    else if (client->player->orientation == 'E')
        _x = get_case(server, client->player->orientation, _x, 1);
    else if (client->player->orientation == 'S')
        _y = get_case(server, client->player->orientation, _y, 1);
    else if (client->player->orientation == 'W')
        _x = get_case(server, client->player->orientation, _x, 1);
    eject_all_players(server, client, _x, _y);
    return 1;
}