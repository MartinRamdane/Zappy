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

void send_ressource_collect(client_t *cli, int ressource, server_t *server)
{
    client_t *tmp = NULL;
    LIST_FOREACH(tmp, &server->head, next) {
        if (tmp->gui_player != NULL) {
            char *buff = malloc(sizeof(char) * 100);
            memset(buff, 0, 100);
            sprintf(buff, "pgt %d %d\n", cli->player->id, ressource);
            send(tmp->socket, buff, strlen(buff), 0);
            free(buff);
        }
    }
    send_map_content_to_all_gui(server);
}

void send_ressource_dropped(client_t *cli, int ressource, server_t *server)
{
    client_t *tmp = NULL;
    LIST_FOREACH(tmp, &server->head, next) {
        if (tmp->gui_player != NULL) {
            char *buff = malloc(sizeof(char) * 100);
            memset(buff, 0, 100);
            sprintf(buff, "pdr %d %d\n", cli->player->id, ressource);
            send(tmp->socket, buff, strlen(buff), 0);
            free(buff);
        }
    }
    send_map_content_to_all_gui(server);
}

void send_map_content_to_all_gui(server_t *server)
{
    client_t *tmp = NULL;
    LIST_FOREACH(tmp, &server->head, next) {
        if (tmp->gui_player != NULL) {
            for (int i = 0; i != server->width; i++) {
                for (int j = 0; j != server->height; j++) {
                    send_tile_with_pos(tmp, server, i, j);
                }
            }
        }
    }
}
