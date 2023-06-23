/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane [WSL: Debian]
** File description:
** player_gui_events
*/

#include "../include/server.h"

void send_player_death(client_t *player, server_t *server)
{
    client_t *tmp = NULL;
    LIST_FOREACH(tmp, &server->head, next) {
        if (tmp->gui_player != NULL) {
            char *buff = malloc(sizeof(char) * 100);
            memset(buff, 0, 100);
            sprintf(buff, "pdi %d\n", player->player->id);
            send(tmp->socket, buff, strlen(buff), 0);
            free(buff);
        }
    }
}