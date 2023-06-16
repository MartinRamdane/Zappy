/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane [WSL: Ubuntu]
** File description:
** random_spawn
*/

#include "../include/server.h"

void spawn_player_on_egg(client_t *cli, server_t *server)
{
    t_egg *egg = NULL;
    LIST_FOREACH(egg, &server->eggs_head, next) {
        if (strcmp(egg->team_name, cli->player->team_name) == 0) {
            cli->player->x = egg->x;
            cli->player->y = egg->y;
            server->game->map[egg->x][egg->y].players = malloc(sizeof(player_queue));
            player_queue *p_queue = malloc(sizeof(player_queue));
            p_queue->player = cli->player; server->player_id++;
            LIST_INSERT_HEAD(&server->game->map[egg->x][egg->y].player_head, p_queue, next);
            if (egg->is_default == false) {
                send_egg_connection_to_guis(server, egg);
            }
            LIST_REMOVE(egg, next);
            return;
        }
    }
}