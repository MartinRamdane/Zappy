/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** handle_client_socket
*/

#include "../include/server.h"

void remove_client(int socket)
{
    struct client *tmp;
    LIST_FOREACH(tmp, &head, next) {
        if (tmp->socket == socket) {
            if (tmp->socket != -1)
                close(tmp->socket);
            LIST_REMOVE(tmp, next);
            if (tmp->buffer)
                free(tmp->buffer);
            if (tmp->uid)
                free(tmp->uid);
            if (tmp->team_name)
                free(tmp->team_name);
            if (tmp->player)
                free(tmp->player);
            if (tmp->gui_player)
                free(tmp->gui_player);
            free(tmp);
            return;
        }
    }
}

void handle_client_data(server_t *s_infos, fd_set *readfds)
{
    struct client *tmp;
    LIST_FOREACH(tmp, &head, next) {
        if (FD_ISSET(tmp->socket, readfds)) {
            check_command(tmp);
        }
    }
}

void check_command(client_t *cli)
{
    int valread; char buffer[MAX_BODY_LENGTH] = {0};
    if ((valread = recv(cli->socket, buffer, 1, 0)) <= 0) {
        remove_client(cli->socket); return;
    } else {
        if (cli->buffer[0] != '\0')
            strcat(cli->buffer, buffer);
        else
            strcpy(cli->buffer, buffer);
    }
    if (cli->buffer[strlen(cli->buffer) - 1] == '\n') {
        cli->buffer[strlen((cli->buffer)) - 1] = '\0';
        printf("Client %d sent: %s\n", cli->socket, cli->buffer);
        // if (commands(cli, cli->buffer) == 1)
        //     return 1;
        free(cli->buffer);
        cli->buffer = malloc(sizeof(char) * MAX_BODY_LENGTH);
        memset(cli->buffer, 0, MAX_BODY_LENGTH);
    }
    return;
}