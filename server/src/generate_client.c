/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** generate_client
*/

#include "../include/server.h"

client_t *generate_client(int socket)
{
    client_t *client = malloc(sizeof(client_t));
    client->socket = socket;
    client->uid = generate_uuid();
    client->buffer = NULL;
    client->team_name = NULL;
    client->player = NULL;
    client->gui_player = NULL;
    client->buffer = malloc(sizeof(char) * MAX_BODY_LENGTH);
    memset(client->buffer, 0, MAX_BODY_LENGTH);
    return client;
}

char *generate_uuid(void)
{
    char *uuid = malloc(sizeof(char) * 37);
    memset(uuid, 0, 37);
    uuid_t binuuid;
    uuid_generate_random(binuuid);
    uuid_unparse(binuuid, uuid);
    return uuid;
}