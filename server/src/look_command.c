/*
** EPITECH PROJECT, 2023
** look_command.c
** File description:
** look_command
*/

#include "../include/server.h"

int get_case(server_t *server, char dir, int tile, int diff)
{
    if (diff == 0) return (tile);
    if (dir == 'N') {
        if (tile - diff < 0) {
            diff = diff - tile; int new_tile = server->height - diff;
            return (new_tile);
        } else {
            return (tile - diff);
        }
    }
    if (dir == 'S') {
        diff = diff % server->height;
        if (tile + diff >= server->height) {
            diff = diff - (server->height - tile); return diff;
        } else
            return (tile + diff);
    }
    if (dir == 'E') {
        diff = diff % server->width;
        if (tile + diff >= server->width) {
            diff = diff - (server->width - tile); return diff;
        } else
            return (tile + diff);
    }
    if (dir == 'W') {
        if (tile - diff < 0) {
            diff = diff - tile; int new_tile = server->width - diff;
            return (new_tile);
        } else {
            return (tile - diff);
        }
    }
    return -1;
}

int get_first_case_id_per_level(server_t *server, int tile, char dir, int level)
{
    int nb_tiles = (get_nb_tiles_per_level(level) - 1) / 2;
    if (dir == 'N') {
        return get_case(server, 'W', tile, nb_tiles);
    }
    if (dir == 'E') {
        return get_case(server, 'N', tile, nb_tiles);
    }
    if (dir == 'S') {
        return get_case(server, 'E', tile, nb_tiles);
    }
    if (dir == 'W') {
        return get_case(server, 'S', tile, nb_tiles);
    }
    return -1;
}

char *get_all_tile_infos(tile *target)
{
    char *buffer = malloc(sizeof(char) * MAX_BODY_LENGTH);
    buffer = memset(buffer, '\0', MAX_BODY_LENGTH); int len = 0;
    if (target->players) {
        strcat(buffer, " player"); len += 7;
    }
    if (target->food > 0) {
        strcat(buffer, " food"); len += 5;
    }
    if (target->linemate > 0) {
        strcat(buffer, " linemate"); len += 9;
    }
    if (target->deraumere > 0) {
        strcat(buffer, " deraumere"); len += 11;
    }
    if (target->sibur > 0) {
        strcat(buffer, " sibur"); len += 6;
    }
    if (target->mendiane > 0) {
        strcat(buffer, " mendiane"); len += 9;
    }
    if (target->phiras > 0) {
        strcat(buffer, " phiras"); len += 7;
    }
    if (target->thystame > 0) {
        strcat(buffer, " thystame"); len += 9;
    }
    if (len > 0)
        buffer[len] = ',';
    else
        buffer[0] = ',';
    return buffer;
}

char *get_all_tiles_per_level(server_t *server, client_t *client, int level)
{
    char *buffer = malloc(sizeof(char) * MAX_BODY_LENGTH);
    buffer[0] = '[';
    char *player_tile = get_all_tile_infos(&server->game->map[client->player->x][client->player->y]);
    strcat(buffer, player_tile);
    for (int i = 1; i <= level; i++) {
        if (client->player->orientation == 'N') {
            int diff_x = client->player->x;
            int diff_y = get_case(server, 'N', client->player->y, (-1 * get_diff_y_per_level(i, client->player->orientation)));
            int first_case = get_first_case_id_per_level(server, diff_x, client->player->orientation, i);
            int nb_tiles_to_print = get_nb_tiles_per_level(i);
            for (int j = 0; j < nb_tiles_to_print; j++) {
                int x = get_case(server, 'E', first_case, j);
                char *tile_infos = get_all_tile_infos(&server->game->map[x][diff_y]);
                strcat(buffer, tile_infos);
            }
        }
        if (client->player->orientation == 'S') {
            int diff_x = client->player->x;
            int diff_y = get_case(server, 'S', client->player->y, (get_diff_y_per_level(i, client->player->orientation)));
            int first_case = get_first_case_id_per_level(server, diff_x, client->player->orientation, i);
            int nb_tiles_to_print = get_nb_tiles_per_level(i);
            for (int j = 0; j < nb_tiles_to_print; j++) {
                int x = get_case(server, 'W', first_case, j);
                char *tile_infos = get_all_tile_infos(&server->game->map[x][diff_y]);
                strcat(buffer, tile_infos);
            }
        }
        if (client->player->orientation == 'W') {
            int diff_x = get_case(server, 'W', client->player->y, (-1 * get_diff_x_per_level(i, client->player->orientation)));
            int diff_y = client->player->y;
            int first_case = get_first_case_id_per_level(server, diff_y, client->player->orientation, i);
            int nb_tiles_to_print = get_nb_tiles_per_level(i);
            for (int j = 0; j < nb_tiles_to_print; j++) {
                int y = get_case(server, 'N', first_case, j);
                char *tile_infos = get_all_tile_infos(&server->game->map[diff_x][y]);
                strcat(buffer, tile_infos);
            }
        }
        if (client->player->orientation == 'E') {
            int diff_x = get_case(server, 'E', client->player->y, (get_diff_x_per_level(i, client->player->orientation)));
            int diff_y = client->player->y;
            int first_case = get_first_case_id_per_level(server, diff_y, client->player->orientation, i);
            int nb_tiles_to_print = get_nb_tiles_per_level(i);
            for (int j = 0; j < nb_tiles_to_print; j++) {
                int y = get_case(server, 'S', first_case, j);
                char *tile_infos = get_all_tile_infos(&server->game->map[diff_x][y]);
                strcat(buffer, tile_infos);
            }
        }
    }
    buffer[strlen(buffer) - 1] = ' '; buffer[strlen(buffer)] = ']';
    return (buffer);
}