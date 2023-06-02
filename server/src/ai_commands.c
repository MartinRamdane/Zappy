/*
** EPITECH PROJECT, 2023
** ai_commands.c
** File description:
** ai_commands
*/

#include "../include/server.h"

void send_task_response(server_t *server, task_t *task, char *cmd)
{
    if (strcmp(cmd, "Forward") == 0) {
        forward_command(server, task->client); return;
    }
}

void forward_command(server_t *server, client_t *client)
{
    if (client->player->state == INCANTATION) return;
    int *pos = create_tuple(client->player->x, client->player->y);
    if (client->player->orientation == 'N')
        pos[1]--;
    else if (client->player->orientation == 'E')
        pos[0]++;
    else if (client->player->orientation == 'S')
        pos[1]++;
    else if (client->player->orientation == 'W')
        pos[0]--;
    move_player(client->player, server->game->map, pos, server);
    send(client->socket, "ok\n", 3, 0);
}