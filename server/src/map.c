/*
** EPITECH PROJECT, 2023
** map.c
** File description:
** map
*/

#include "../include/server.h"

tile **generate_map(server_t *infos)
{
    tile **map = malloc(sizeof(tile *) * infos->width);
    memset(map, 0, sizeof(tile *) * infos->width);
    for (int x = 0; x < infos->width; x++) {
        map[x] = malloc(sizeof(tile) * infos->height);
        memset(map[x], 0, sizeof(tile) * infos->height);
        for (int y = 0; y < infos->height; y++) {
            map[x][y].x = x; map[x][y].y = y;
            map[x][y].food = 0;
            map[x][y].linemate = 0;
            map[x][y].deraumere = 0;
            map[x][y].sibur = 0;
            map[x][y].mendiane = 0;
            map[x][y].phiras = 0;
            map[x][y].thystame = 0;
            LIST_INIT(&map[x][y].player_head);
        }
    }
    return map;
}

int *resources_ratio(server_t infos)
{
    int *resources = malloc(sizeof(int) * 7);
    resources[0] = infos.width * infos.height * 0.5;
    resources[1] = infos.width * infos.height * 0.3;
    resources[2] = infos.width * infos.height * 0.15;
    resources[3] = infos.width * infos.height * 0.1;
    resources[4] = infos.width * infos.height * 0.1;
    resources[5] = infos.width * infos.height * 0.08;
    resources[6] = infos.width * infos.height * 0.05;
    return resources;
}

int remaining_resources(int *resources)
{
    for (int i = 0; i < 7; i++) {
        if (resources[i] > 0)
            return (1);
    }
    return 0;
}

void fill_map(server_t infos, tile **map)
{
    int *ratio = resources_ratio(infos);
    int *q = get_resources_quantities(ratio, infos);
    int *r = get_remaining_resources(ratio, infos);
    for (int i = 0; i < infos.width; i++) {
        for (int j = 0; j < infos.height; j++) {
            map[i][j].food += q[0]; map[i][j].linemate += q[1];
            map[i][j].deraumere += q[2]; map[i][j].sibur += q[3];
            map[i][j].mendiane += q[4]; map[i][j].phiras += q[5];
            map[i][j].thystame += q[6];
        }
    }
    srand(time(0));
    put_food_resource(infos, map, r[0]);
    put_linemate_resource(infos, map, r[1]);
    put_deraumere_resource(infos, map, r[2]);
    put_sibur_resource(infos, map, r[3]);
    put_mendiane_resource(infos, map, r[4]);
    put_phiras_resource(infos, map, r[5]);
    put_thystame_resource(infos, map, r[6]);
    free(ratio);
    free(q);
    free(r);
}
