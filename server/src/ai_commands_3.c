/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane [WSL: Ubuntu]
** File description:
** ai_commands_3
*/

#include "../include/server.h"

void fork_command(client_t *client, server_t *server)
{
    t_egg *egg = malloc(sizeof(t_egg));
    egg->team_name = client->player->team_name;
    egg->x = client->player->x;
    egg->y = client->player->y;
    egg->id = server->egg_id; server->egg_id++;
    egg->is_default = false;
    egg->parent_id = client->player->id;
    LIST_INSERT_HEAD(&server->eggs_head, egg, next);
    send(client->socket, "ok\n", 3, 0);
    send_new_egg_to_guis(server, egg);
}

void life_cycle_command(server_t *server, client_t *client)
{
    if (client->player->inv->food > 0 && client->player->state == ALIVE
    && client->player->level <= 7) {
        client->player->inv->food--;
    } else if (client->player->inv->food <= 0 && client->player->level <= 7) {
        send(client->socket, "dead\n", 5, 0);
        client->player->is_dead = true;
        close(client->socket);
        send_player_death(client, server);
        remove_client(client->socket, server);
        return;
    }
    char *buffer_life = strdup("LifeCycle");
    double task_food_time = calculate_time_for_task(server, buffer_life);
    add_task(server, buffer_life, task_food_time, client);
    free(buffer_life);
}