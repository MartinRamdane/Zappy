/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane [WSL: Debian]
** File description:
** player_gui_commands
*/

#include "../include/server.h"

void event_player_expulsion(client_t *cli, server_t *server)
{
    client_t *tmp = NULL;
    LIST_FOREACH(tmp, &server->head, next) {
        if (tmp->gui_player != NULL) {
            char *buff = malloc(sizeof(char) * 100);
            memset(buff, 0, 100);
            sprintf(buff, "pex %d\n", cli->player->id);
            send(tmp->socket, buff, strlen(buff), 0);
            free(buff);
        }
    }
}

void event_player_broadcast(client_t *cli, server_t *server, char *msg)
{
    client_t *tmp = NULL;
    LIST_FOREACH(tmp, &server->head, next) {
        if (tmp->gui_player != NULL) {
            char *buff = malloc(sizeof(char) * 100);
            memset(buff, 0, 100);
            sprintf(buff, "pbc %d %s\n", cli->player->id, msg);
            send(tmp->socket, buff, strlen(buff), 0);
            free(buff);
        }
    }
}

void event_player_incantation_start(client_t *cli, server_t *server)
{
    client_t *tmp = NULL;
    LIST_FOREACH(tmp, &server->head, next) {
        if (tmp->gui_player != NULL) {
            char *buff = malloc(sizeof(char) * 100);
            memset(buff, 0, 100);
            sprintf(buff, "pic %d %d %d %d\n", cli->player->x, cli->player->y,
            cli->player->level, cli->player->id);
            send(tmp->socket, buff, strlen(buff), 0);
            free(buff);
        }
    }
}

void event_player_incantation_end(client_t *cli, server_t *server, int res)
{
    client_t *tmp = NULL;
    LIST_FOREACH(tmp, &server->head, next) {
        if (tmp->gui_player != NULL) {
            char *buff = malloc(sizeof(char) * 100);
            memset(buff, 0, 100);
            sprintf(buff, "pie %d %d %d\n", cli->player->x, cli->player->y,
            res);
            send(tmp->socket, buff, strlen(buff), 0);
            if (res == 1) {
                memset(buff, 0, 100);
                sprintf(buff, "plv %d %d\n", cli->player->id,
                cli->player->level);
                send(tmp->socket, buff, strlen(buff), 0);
            }
            free(buff);
        }
    }
}

void send_all_player_pos(client_t *cli, server_t *server)
{
    client_t *tmp = NULL;
    LIST_FOREACH(tmp, &server->head, next) {
        if (tmp->player != NULL) {
            send_playerdata_to_gui(cli, tmp);
        }
    }
}
