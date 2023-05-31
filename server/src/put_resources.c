/*
** EPITECH PROJECT, 2023
** put_resources.c
** File description:
** put_resources
*/

#include "../include/server.h"

void put_food_resource(server_t infos, tile **map, int r)
{
    for (int i = 0; i < r; i++) {
        int x = rand() % infos.width;
        int y = rand() % infos.height;
        map[x][y].food++;
    }
}

void put_linemate_resource(server_t infos, tile **map, int r)
{
    for (int i = 0; i < r; i++) {
        int x = rand() % infos.width;
        int y = rand() % infos.height;
        map[x][y].linemate++;
    }
}

void put_deraumere_resource(server_t infos, tile **map, int r)
{
    for (int i = 0; i < r; i++) {
        int x = rand() % infos.width;
        int y = rand() % infos.height;
        map[x][y].deraumere++;
    }
}

void put_sibur_resource(server_t infos, tile **map, int r)
{
    for (int i = 0; i < r; i++) {
        int x = rand() % infos.width;
        int y = rand() % infos.height;
        map[x][y].sibur++;
    }
}

void put_mendiane_resource(server_t infos, tile **map, int r)
{
    for (int i = 0; i < r; i++) {
        int x = rand() % infos.width;
        int y = rand() % infos.height;
        map[x][y].mendiane++;
    }
}