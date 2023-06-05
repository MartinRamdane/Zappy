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
    if (strcmp(cmd, "Right") == 0) {
        right_command(task->client); return;
    }
    if (strcmp(cmd, "Left") == 0) {
        left_command(task->client); return;
    }
    if (strcmp(cmd, "Inventory") == 0) {
        inventory_command(task->client); return;
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

void right_command(client_t *client)
{
    if (client->player->state == INCANTATION) return;
    if (client->player->orientation == 'N')
        client->player->orientation = 'E';
    else if (client->player->orientation == 'E')
        client->player->orientation = 'S';
    else if (client->player->orientation == 'S')
        client->player->orientation = 'W';
    else if (client->player->orientation == 'W')
        client->player->orientation = 'N';
    send(client->socket, "ok\n", 3, 0);
}

void left_command(client_t *client)
{
    if (client->player->state == INCANTATION) return;
    if (client->player->orientation == 'N')
        client->player->orientation = 'W';
    else if (client->player->orientation == 'E')
        client->player->orientation = 'N';
    else if (client->player->orientation == 'S')
        client->player->orientation = 'E';
    else if (client->player->orientation == 'W')
        client->player->orientation = 'S';
    send(client->socket, "ok\n", 3, 0);
}