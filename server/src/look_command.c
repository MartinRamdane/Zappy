/*
** EPITECH PROJECT, 2023
** look_command.c
** File description:
** look_command
*/

#include "../include/server.h"

int get_case(server_t *server, char dir, int tile, int diff)
{
    if (dir == 'N') {
        if (tile - diff < 0) {
            diff = diff - tile; int new_tile = server->height - diff;
            return (new_tile);
        }
    }
    if (dir == 'S') {
        diff = diff % server->height;
        if (tile + diff >= server->height) {
            diff = diff - (server->height - tile); return diff;
        }
    }
    if (dir == 'E') {
        diff = diff % server->width;
        if (tile + diff >= server->width) {
            diff = diff - (server->width - tile); return diff;
        }
    }
    if (dir == 'W') {
        if (tile - diff < 0) {
            diff = diff - tile; int new_tile = server->width - diff;
            return (new_tile);
        }
    }
    return -1;
}

int get_nb_tiles_per_level(int level)
{
    int value = (level - 1) * 2;
    return (value + 3);
}

// return l'ID de la tile
int get_first_case_id_per_level(server_t *server, int tile, char dir, int level)
{
    int nb_tiles = (get_nb_tiles_per_level(level) - 1) / 2;
    if (dir == 'N') {
        return get_case(server, 'W', tile, nb_tiles) - 1;
    }
    if (dir == 'E') {
        return get_case(server, 'N', tile, nb_tiles) - 1;
    }
    if (dir == 'S') {
        return get_case(server, 'E', tile, nb_tiles) - 1;
    }
    if (dir == 'W') {
        return get_case(server, 'S', tile, nb_tiles) - 1;
    }
    return -1;
}

char *get_all_tile_infos(tile *target)
{
    char *buffer = malloc(sizeof(char) * MAX_BODY_LENGTH); int len = 0;
    if (target->player) {
        strcat(buffer, "player "); len += 7;
    }
    if (target->food > 0) {
        strcat(buffer, "food "); len += 5;
    }
    if (target->linemate > 0) {
        strcat(buffer, "linemate "); len += 9;
    }
    if (target->deraumere > 0) {
        strcat(buffer, "deraumere "); len += 11;
    }
    if (target->sibur > 0) {
        strcat(buffer, "sibur "); len += 6;
    }
    if (target->mendiane > 0) {
        strcat(buffer, "mendiane "); len += 9;
    }
    if (target->phiras > 0) {
        strcat(buffer, "phiras "); len += 7;
    }
    if (target->thystame > 0) {
        strcat(buffer, "thystame "); len += 9;
    }
    if (len > 0) {
        buffer[len - 1] = ','; buffer[len] = '\0';
    } else {
        buffer[0] = ','; buffer[1] = '\0';
    }
    return buffer;
}

char *get_all_tiles_per_level(server_t *server, client_t *client, int level)
{
    char *buffer = malloc(sizeof(char) * MAX_BODY_LENGTH);
    buffer[0] = '[';
    char *test = get_all_tile_infos(&server->game->map[client->player->x][client->player->y]);
    strcat(buffer, test);
    buffer[strlen(buffer) - 1] = ']';
    printf("info: %s\n", buffer);
}