/*
** EPITECH PROJECT, 2023
** ai_commands_2.c
** File description:
** ai_commands_2
*/

#include "../include/server.h"

void inventory_command(client_t *client)
{
    if (client->player->state == INCANTATION) return;
    char *response = malloc(sizeof(char) * MAX_BODY_LENGTH);
    sprintf(response, "[food %d, linemate %d, deraumere %d, sibur %d, mendiane %d, phiras %d, thystame %d]\n", client->player->inv->food,
    client->player->inv->linemate, client->player->inv->deraumere,
    client->player->inv->sibur, client->player->inv->mendiane,
    client->player->inv->phiras, client->player->inv->thystame);
    send(client->socket, response, strlen(response), 0);
}

void look_command(server_t *server, client_t *client)
{
    char *buff = get_all_tiles_per_level(server, client, client->player->level);
    send(client->socket, buff, strlen(buff), 0);
    send(client->socket, "\n", 1, 0);
}

void set_command(server_t *server, client_t *client, char *buffer)
{
    debug_print_player_inventory(client);
    int val = set_object(server, client, buffer);
    if (val == 0) {
        send(client->socket, "ko\n", 3, 0);
    } else {
        debug_print_map(server, server->game->map);
        debug_print_player_inventory(client);
        send(client->socket, "ok\n", 3, 0);
    }
}

void take_command(server_t *server, client_t *client, char *buffer)
{
    debug_print_player_inventory(client);
    int val = take_object(server, client, buffer);
    if (val == 0) {
        send(client->socket, "ko\n", 3, 0);
    } else {
        debug_print_map(server, server->game->map);
        debug_print_player_inventory(client);
        send(client->socket, "ok\n", 3, 0);
    }
}

void eject_command(server_t *server, client_t *client)
{
    if (eject_player(server, client) == 1) {
        send(client->socket, "ok\n", 3, 0);
    } else {
        send(client->socket, "ko\n", 3, 0);
    }
}