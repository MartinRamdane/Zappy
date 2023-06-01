/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane [WSL: Ubuntu]
** File description:
** handle_received_data
*/

#include "../include/server.h"

int commands(server_t *server, client_t *client, char *buffer)
{
    if (add_client_to_team(server, buffer, client) == 1)
        return 0;
    if (strcmp(client->buffer, "remove task") == 0) {
        printf("ca REMOVE ici\n");
        remove_first_task(server);
    } else {
        add_task(server, client->buffer, 5);
    }
    debug_print_task_queue(server);
    return 0;
}
