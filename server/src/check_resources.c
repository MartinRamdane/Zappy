/*
** EPITECH PROJECT, 2023
** check_resources.c
** File description:
** check_resources
*/

#include "../include/server.h"

int *take_all_resources_from_map(server_t infos)
{
    int *resources = malloc(sizeof(int) * 7);
    for (int i = 0; i < 7; i++) {
        resources[i] = 0;
    }
    for (int i = 0; i < infos.width; i++) {
        for (int j = 0; j < infos.height; j++) {
            resources[0] += infos.game->map[i][j].food;
            resources[1] += infos.game->map[i][j].linemate;
            resources[2] += infos.game->map[i][j].deraumere;
            resources[3] += infos.game->map[i][j].sibur;
            resources[4] += infos.game->map[i][j].mendiane;
            resources[5] += infos.game->map[i][j].phiras;
            resources[6] += infos.game->map[i][j].thystame;
        }
    }
    return resources;
}

void respawn_map_2(server_t infos, tile **map, int *resources)
{
    if (resources[3] < (infos.width * infos.height * 0.1)) {
        int to_add = (infos.width * infos.height * 0.1) - resources[3];
        printf("[DEBUG]: Respawn sibur %d\n", to_add);
        put_sibur_resource(infos, map, to_add);
    }
    if (resources[4] < (infos.width * infos.height * 0.1)) {
        int to_add = (infos.width * infos.height * 0.1) - resources[4];
        printf("[DEBUG]: Respawn mendiane %d\n", to_add);
        put_mendiane_resource(infos, map, to_add);
    }
    if (resources[5] < (infos.width * infos.height * 0.08)) {
        int to_add = (infos.width * infos.height * 0.08) - resources[5];
        printf("[DEBUG]: Respawn phiras %d\n", to_add);
        put_phiras_resource(infos, map, to_add);
    }
    if (resources[6] < (infos.width * infos.height * 0.05)) {
        int to_add = (infos.width * infos.height * 0.05) - resources[6];
        printf("[DEBUG]: Respawn thystame %d\n", to_add);
        put_thystame_resource(infos, map, to_add);
    }
    free(resources);
}

void respawn_map(server_t infos, tile **map)
{
    int *resources_remaining = take_all_resources_from_map(infos);
    int width = infos.width, height = infos.height; int to_add = 0;
    if (resources_remaining[0] < (width * height * 0.5)) {
        to_add = (width * height * 0.5) - resources_remaining[0];
        printf("[DEBUG]: Respawn food %d\n", to_add);
        put_food_resource(infos, map, to_add);
    }
    if (resources_remaining[1] < (width * height * 0.3)) {
        to_add = (width * height * 0.3) - resources_remaining[1];
        printf("[DEBUG]: Respawn linemate %d\n", to_add);
        put_linemate_resource(infos, map, to_add);
    }
    if (resources_remaining[2] < (width * height * 0.15)) {
        to_add = (width * height * 0.15) - resources_remaining[2];
        printf("[DEBUG]: Respawn deraumere %d\n", to_add);
        put_deraumere_resource(infos, map, to_add);
    }
    respawn_map_2(infos, map, resources_remaining);
}