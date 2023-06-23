/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane [WSL: Ubuntu]
** File description:
** game_gui_events
*/

#include "../include/server.h"

void event_end_of_game(server_t *server, team_t *winners)
{
    client_t *tmp = NULL;
    LIST_FOREACH(tmp, &server->head, next) {
        if (tmp->gui_player != NULL) {
            char *buff = malloc(sizeof(char) * 100);
            memset(buff, 0, 100);
            sprintf(buff, "seg %s\n", winners->name);
            send(tmp->socket, buff, strlen(buff), 0);
            free(buff);
        }
    }
}
