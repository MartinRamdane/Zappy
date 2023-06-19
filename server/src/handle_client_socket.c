/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** handle_client_socket
*/

#include "../include/server.h"

void handle_client_data(server_t *s_infos, fd_set *readfds)
{
    struct client *tmp = NULL;
    LIST_FOREACH(tmp, &s_infos->head, next) {
        if (FD_ISSET(tmp->socket, readfds)) {
            check_command(tmp, s_infos);
        }
    }
}

void check_command(client_t *cli, server_t *s_infos)
{
    int valread; char buffer[MAX_BODY_LENGTH] = {0};
    if ((valread = recv(cli->socket, buffer, 1, 0)) <= 0) {
        remove_client(cli->socket, s_infos); return;
    } else {
        if (cli->buffer[0] != '\0')
            strcat(cli->buffer, buffer);
        else
            strcpy(cli->buffer, buffer);
    }
    if (cli->buffer[strlen(cli->buffer) - 1] == '\n') {
        cli->buffer[strlen((cli->buffer)) - 1] = '\0';
        printf("Client %d sent: %s\n", cli->socket, cli->buffer);
        if (commands(s_infos, cli, cli->buffer) == 1)
            return;
        memset(cli->buffer, 0, MAX_BODY_LENGTH);
    }
    return;
}