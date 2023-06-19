/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane [WSL: Ubuntu]
** File description:
** remove_player
*/

#include "../include/server.h"

void remove_client(int socket, server_t *s_infos)
{
    struct client *tmp;
    LIST_FOREACH(tmp, &s_infos->head, next) {
        if (tmp->socket == socket) {
            if (tmp->player != NULL) {
                remove_player_from_tile(tmp, s_infos);
                remove_task_of_player(tmp, s_infos);
                send_player_death(tmp, s_infos);
                regenerate_eggs(s_infos);
            }
            remove_client_from_team(tmp, s_infos);
            if (tmp->socket != -1)
                close(tmp->socket);
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
            LIST_REMOVE(tmp, next);
            return;
        }
    }
}

void remove_player_from_tile(client_t *cli, server_t *s_infos)
{
    t_player_queue *tmp = NULL;
    LIST_FOREACH(tmp, &s_infos->game->map[cli->player->x][cli->player->y].player_head, next) {
        if (strcmp(tmp->player->uid, cli->player->uid) == 0) {
            LIST_REMOVE(tmp, next);
            free(tmp);
            return;
        }
    }
}

void remove_task_of_player(client_t *cli, server_t *s_infos)
{
    task_t *tmp = NULL;
    LIST_FOREACH(tmp, &s_infos->task_head, next) {
        if (tmp->client && strcmp(tmp->client->uid, cli->player->uid) == 0) {
            LIST_REMOVE(tmp, next);
            return remove_task_of_player(cli, s_infos);
        }
    }
}