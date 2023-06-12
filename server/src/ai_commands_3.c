/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane [WSL: Ubuntu]
** File description:
** ai_commands_3
*/

#include "../include/server.h"

void fork_command(client_t *client, server_t *server)
{
    tile *mytile = &server->game->map[client->player->x][client->player->y];
    t_egg *egg = malloc(sizeof(t_egg));
    egg->team_name = client->player->team_name;
    egg->x = client->player->x;
    egg->y = client->player->y;
    egg->id = server->egg_id; server->egg_id++;
    egg->parent_id = client->player->id;
    LIST_INSERT_HEAD(&mytile->eggs_head, egg, next);
    send(client->socket, "ok\n", 3, 0);
    send_new_egg_to_guis(server, egg);
}
