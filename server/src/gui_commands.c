/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane [WSL: Ubuntu]
** File description:
** gui_commands
*/

#include "../include/server.h"

int check_gui_commands(char *buffer, client_t *client, server_t *server)
{
    if (client->gui_player == NULL) return 0;
    if (strcmp(buffer, "msz") == 0) {
        send_map_size(client, server); return 1;
    }
    if (strcmp(buffer, "sgt") == 0) {
        send_time_unit(client, server); return 1;
    }
    if (strcmp(buffer, "tna") == 0) {
        send_teams(client, server); return 1;
    }
    if (strstr(buffer, "bct" ) != NULL) {
        send_tile_content(client, server, buffer); return 1;
    }
    if (strcmp(buffer, "mct") == 0) {
        send_map_content(client, server); return 1;
    }
    if (strstr(buffer, "ppo") != NULL) {
        send_player_pos(client, server, buffer); return 1;
    }
    return check_others_gui_cmd(buffer, client, server);
}

void send_map_size(client_t *client, server_t *server)
{
    char *buffer = malloc(sizeof(char) * 100);
    memset(buffer, 0, 100);
    sprintf(buffer, "msz %d %d\n", server->width, server->height);
    send(client->socket, buffer, strlen(buffer), 0);
    free(buffer);
    return;
}

void send_time_unit(client_t *client, server_t *server)
{
    char *buffer = malloc(sizeof(char) * 100);
    memset(buffer, 0, 100);
    sprintf(buffer, "sgt %f\n", server->freq);
    send(client->socket, buffer, strlen(buffer), 0);
    free(buffer);
    return;
}

void send_teams(client_t *client, server_t *server)
{
    char *buffer = malloc(sizeof(char) * 100);
    memset(buffer, 0, 100);
    team_t *tmp = NULL;
    LIST_FOREACH(tmp, &server->team_head, next) {
        sprintf(buffer, "tna %s\n", tmp->name);
        send(client->socket, buffer, strlen(buffer), 0);
        memset(buffer, 0, 100);
    }
    free(buffer);
    return;
}

void send_tile_content(client_t *client, server_t *server, char *msg)
{
    strtok(msg, " ");
    char *x_val = strtok(NULL, " ");
    char *y_val = strtok(NULL, " ");
    if (x_val == NULL || y_val == NULL || server->width < atoi(x_val) ||
    server->height < atoi(y_val)) {
        send(client->socket, GUI_UNKNOWN_PARAM, strlen(GUI_UNKNOWN_PARAM), 0);
        return;
    }
    int x = atoi(x_val);
    int y = atoi(y_val);
    char *buffer = malloc(sizeof(char) * 100);
    memset(buffer, 0, 100);
    tile val = server->game->map[x][y];
    sprintf(buffer, "bct %d %d %d %d %d %d %d %d %d\n", x, y, val.food,
    val.linemate, val.deraumere, val.sibur, val.mendiane,
    val.phiras, val.thystame);
    send(client->socket, buffer, strlen(buffer), 0);
    free(buffer);
    return;
}
