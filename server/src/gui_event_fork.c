/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane [WSL: Ubuntu]
** File description:
** event_fork
*/

#include "../include/server.h"

void send_new_egg_to_guis(server_t *server, t_egg *egg)
{
    client_t *tmp = NULL;
    char *buff = malloc(sizeof(char) * 100);
    sprintf(buff, "enw %d %d %d %d\n", egg->id, egg->parent_id, egg->x, egg->y);
    LIST_FOREACH(tmp, &server->head, next) {
        if (tmp->gui_player != NULL)
            send(tmp->socket, buff, strlen(buff), 0);
    }
    free(buff);
}

void send_egg_death_to_guis(server_t *server, t_egg *egg)
{
    client_t *tmp = NULL;
    char *buff = malloc(sizeof(char) * 100);
    memset(buff, 0, 100);
    sprintf(buff, "edi %d\n", egg->id);
    LIST_FOREACH(tmp, &server->head, next) {
        if (tmp->gui_player != NULL)
            send(tmp->socket, buff, strlen(buff), 0);
    }
    free(buff);
}

void send_egg_connection_to_guis(server_t *server, t_egg *egg)
{
    client_t *tmp = NULL;
    char *buff = malloc(sizeof(char) * 100);
    memset(buff, 0, 100);
    sprintf(buff, "ebo %d\n", egg->id);
    LIST_FOREACH(tmp, &server->head, next) {
        if (tmp->gui_player != NULL)
            send(tmp->socket, buff, strlen(buff), 0);
    }
    free(buff);
}