/*
** EPITECH PROJECT, 2023
** broadcast.c
** File description:
** broadcast
*/

#include "../include/server.h"

l_tile *get_all_listen_tiles_position(server_t *server, player *player)
{
    l_tile *listen_tiles = malloc(sizeof(l_tile) * 8);
    int _x = player->x; int _y = player->y;
    for (int i = 0; i < 8; i++) {
        listen_tiles[i].x = _x; listen_tiles[i].y = _y;
        listen_tiles[i].player = player;
    }
    if (player->orientation == 'N')
        listen_tiles = get_north_case(server, listen_tiles);
    if (player->orientation == 'S')
        listen_tiles = get_south_case(server, listen_tiles);
    if (player->orientation == 'W')
        listen_tiles = get_west_case(server, listen_tiles);
    if (player->orientation == 'E')
        listen_tiles = get_east_case(server, listen_tiles);
    return listen_tiles;
}

int *compare_diff(int **diff)
{
    int *res = malloc(sizeof(int) * 4);
    res[0] = 1000; res[1] = 1000;
    for (int i = 0; i < 8; i++) {
        //printf("diff[%d][0] = %d diff[%d][1] = %d\n", i, diff[i][0], i, diff[i][1]);
        if (diff[i][0] < res[0]) {
            res[0] = diff[i][0]; res[2] = diff[i][2];
        } if (diff[i][0] == res[0]) {
          //  printf("same y: %d\n", diff[i][0]);
            if (diff[i][1] < res[1]) {
                res[1] = diff[i][1];
                res[3] = diff[i][3];
            }
        }
    }
    return res;
}

int compare_listen_tiles(l_tile *listen_tiles, int x, int y)
{
    int **diff = malloc(sizeof(int *) * 8);
    memset(diff, 0, sizeof(int *) * 8);
    int **target_tiles = malloc(sizeof(int *) * 8);
    memset(target_tiles, 0, sizeof(int *) * 8);
    for (int i = 0; i < 8; i++)
        if (listen_tiles[i].x == x && listen_tiles[i].y == y)
            return listen_tiles[i].id;
    for (int i = 0; i < 8; i++) {
        diff[i] = malloc(sizeof(int) * 2);
        target_tiles[i] = malloc(sizeof(int) * 4);
    }
    for (int i = 0; i < 8; i++) {
        if (listen_tiles[i].x > x) {
            diff[i][0] = listen_tiles[i].x - x; diff[i][2] = 0;
        } else {
            diff[i][0] = x - listen_tiles[i].x; diff[i][2] = 1;
        } if (listen_tiles[i].y > y) {
            diff[i][1] = listen_tiles[i].y - y; diff[i][3] = 0;
        } else {
            diff[i][1] = y - listen_tiles[i].y; diff[i][3] = 1;
        }
    }
    int *res = compare_diff(diff);
    int new_x = 0, new_y = 0;
    if (res[2] == 1) new_x = x - res[0];
    else new_x = x + res[0];
    if (res[3] == 1) new_y = y - res[1];
    else new_y = y + res[1];
    for (int i = 0; i < 8; i++) {
        if (listen_tiles[i].x == new_x && listen_tiles[i].y == new_y)
            return listen_tiles[i].id;
    }
    free(res);
    free(diff);
    free(target_tiles);
    return -1;
}

void send_broadcast(server_t *server, client_t *sender, client_t *client, char *msg)
{
    l_tile *listen_tiles = get_all_listen_tiles_position(server, client->player);
    int id = 0;
    if (client->player->x != sender->player->x ||
            client->player->y != sender->player->y) {
        id = compare_listen_tiles(listen_tiles, sender->player->x, sender->player->y);
    }
    char *to_send = malloc(sizeof(char) * MAX_BODY_LENGTH);
    sprintf(to_send, "message %d, %s\n", id, msg);
    send(client->socket, to_send, strlen(to_send), 0);
    free(to_send);
    free(listen_tiles);
}

void broadcast_command(server_t *server, client_t *client, char *msg)
{
    msg += 10;
    client_t *tmp = NULL;
    send(client->socket, "ok\n", 3, 0);
    LIST_FOREACH(tmp, &server->head, next) {
        if (tmp->player == NULL) {
            continue;
        }
        if (tmp->player->state != INCANTATION && strcmp(tmp->player->uid, client->player->uid) != 0) {
            send_broadcast(server, client, tmp, msg);
        }
    }
    event_player_broadcast(client, server, msg);
}