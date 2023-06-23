/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane [WSL: Ubuntu]
** File description:
** gui_commands_3
*/

#include "../include/server.h"

int check_others_gui_cmd(char *buffer, client_t *client, server_t *server)
{
    if (strstr(buffer, "plv") != NULL) {
        send_player_level(client, server, buffer); return 1;
    }
    if (strstr(buffer, "pin") != NULL) {
        send_player_inventory(client, server, buffer); return 1;
    }
    if (strstr(buffer, "sst") != NULL) {
        change_time_unit(client, server, buffer); return 1;
    }
    return 0;
}

void send_player_pos(client_t *cli, server_t *server, char *buff)
{
    strtok(buff, " "); char *id = strtok(NULL, " ");
    if (id == NULL) {
        send(cli->socket, GUI_UNKNOWN_PARAM, strlen(GUI_UNKNOWN_PARAM), 0);
        return;
    }
    char *buffer = malloc(sizeof(char) * 100); memset(buffer, 0, 100);
    client_t *tmp = NULL;
    LIST_FOREACH(tmp, &server->head, next) {
        if (tmp->player && tmp->player->id == atoi(id)) {
            sprintf(buffer, "ppo %d %d %d %d\n", tmp->player->id,
            tmp->player->x, tmp->player->y,
            orientation_to_number(tmp->player->orientation));
            send(cli->socket, buffer, strlen(buffer), 0);
            free(buffer);
            return;
        }
    } free(buffer);
    send(cli->socket, GUI_UNKNOWN_PARAM, strlen(GUI_UNKNOWN_PARAM), 0);
}

void send_player_level(client_t *cli, server_t *server, char *buff)
{
    strtok(buff, " "); char *id = strtok(NULL, " ");
    if (id == NULL) {
        send(cli->socket, GUI_UNKNOWN_PARAM, strlen(GUI_UNKNOWN_PARAM), 0);
        return;
    }
    char *buffer = malloc(sizeof(char) * 100); memset(buffer, 0, 100);
    client_t *tmp = NULL;
    LIST_FOREACH(tmp, &server->head, next) {
        if (tmp->player && tmp->player->id == atoi(id)) {
            sprintf(buffer, "plv %d %d\n", tmp->player->id,
            tmp->player->level);
            send(cli->socket, buffer, strlen(buffer), 0);
            free(buffer);
            return;
        }
    } free(buffer);
    send(cli->socket, GUI_UNKNOWN_PARAM, strlen(GUI_UNKNOWN_PARAM), 0);
}

void send_player_inventory(client_t *cli, server_t *server, char *buff)
{
    strtok(buff, " "); char *id = strtok(NULL, " ");
    if (id == NULL) {
        send(cli->socket, GUI_UNKNOWN_PARAM, strlen(GUI_UNKNOWN_PARAM), 0);
        return;
    }
    char *buffer = malloc(sizeof(char) * 100); memset(buffer, 0, 100);
    client_t *tmp = NULL;
    LIST_FOREACH(tmp, &server->head, next) {
        if (tmp->player && tmp->player->id == atoi(id)) {
            sprintf(buffer, "pin %d %d %d %d %d %d %d %d %d %d\n",
            tmp->player->id, tmp->player->x, tmp->player->y,
            tmp->player->inv->food, tmp->player->inv->linemate,
            tmp->player->inv->deraumere, tmp->player->inv->sibur,
            tmp->player->inv->mendiane, tmp->player->inv->phiras,
            tmp->player->inv->thystame);
            send(cli->socket, buffer, strlen(buffer), 0);
            free(buffer);
            return;
        }
    } free(buffer);
    send(cli->socket, GUI_UNKNOWN_PARAM, strlen(GUI_UNKNOWN_PARAM), 0);
}
