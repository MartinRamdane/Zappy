/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane [WSL: Ubuntu]
** File description:
** incantation
*/

#include "../include/server.h"

void make_incantation_for_all_players(server_t *server, client_t *client)
{
    client_t *tmp = NULL;
    client_t *clientList[100];
    int i = 0;
    LIST_FOREACH(tmp, &server->head, next) {
        if (tmp->player && tmp->player->x == client->player->x &&
        tmp->player->y == client->player->y && tmp->player->level ==
        client->player->level && tmp->player->level < 8 && tmp->player->state == INCANTATION) {
            clientList[i] = tmp;
            i++;
        }
    }
    for (int j = 0; j < i; j++) {
        clientList[j]->player->level++;
        char *buff = malloc(sizeof(char) * MAX_BODY_LENGTH);
        sprintf(buff, "Current level: %d\n", clientList[j]->player->level);
        send(clientList[j]->socket, buff, strlen(buff), 0);
        event_player_incantation_end(clientList[j], server, 1);
        remove_incantation_task_for_player(server, clientList[j]);
        free(buff);
        clientList[j]->player->state = ALIVE;
    }
}

void remove_incantation_task_for_player(server_t *server, client_t *client)
{
    task_t *tmp = NULL;
    LIST_FOREACH(tmp, &server->task_head, next) {
        if (tmp->client && strcmp(tmp->client->uid, client->player->uid) == 0 &&
        strcmp(tmp->cmd, "Incantation") == 0) {
            LIST_REMOVE(tmp, next);
            return;
        }
    }
}
