/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane [WSL: Debian]
** File description:
** gui_events
*/

#include "../include/server.h"

void send_new_player_pos(client_t *cli, server_t *server)
{
    client_t *tmp = NULL;
    LIST_FOREACH(tmp, &server->head, next) {
        if (tmp->gui_player != NULL) {
            char *buff = malloc(sizeof(char) * 100);
            memset(buff, 0, 100);
            sprintf(buff, "ppo %d %d %d %d\n", cli->player->id,
            cli->player->x, cli->player->y,
            orientation_to_number(cli->player->orientation));
            send(tmp->socket, buff, strlen(buff), 0);
            free(buff);
        }
    }
}
