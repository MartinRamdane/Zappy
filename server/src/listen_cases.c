/*
** EPITECH PROJECT, 2023
** listen_cases.c
** File description:
** listen_cases
*/

#include "../include/server.h"

l_tile *get_north_case(server_t *server, l_tile *listen_tiles)
{
    listen_tiles[0].y = get_case(server, 'N', listen_tiles[0].y, 1);
    listen_tiles[0].id = 1; listen_tiles[1] = listen_tiles[0];
    listen_tiles[1].x = get_case(server, 'W', listen_tiles[1].x, 1);
    listen_tiles[1].id = 2; listen_tiles[2] = listen_tiles[1];
    listen_tiles[2].y = get_case(server, 'S', listen_tiles[2].y, 1);
    listen_tiles[2].id = 3; listen_tiles[3] = listen_tiles[2];
    listen_tiles[3].y = get_case(server, 'S', listen_tiles[3].y, 1);
    listen_tiles[3].id = 4; listen_tiles[4] = listen_tiles[3];
    listen_tiles[4].x = get_case(server, 'E', listen_tiles[4].x, 1);
    listen_tiles[4].id = 5; listen_tiles[5] = listen_tiles[4];
    listen_tiles[5].x = get_case(server, 'E', listen_tiles[5].x, 1);
    listen_tiles[5].id = 6; listen_tiles[6] = listen_tiles[5];
    listen_tiles[6].y = get_case(server, 'N', listen_tiles[6].y, 1);
    listen_tiles[6].id = 7; listen_tiles[7] = listen_tiles[6];
    listen_tiles[7].y = get_case(server, 'N', listen_tiles[7].y, 1);
    listen_tiles[7].id = 8;
    return listen_tiles;
}

l_tile *get_south_case(server_t *server, l_tile *listen_tiles)
{
    listen_tiles[0].y = get_case(server, 'S', listen_tiles[0].y, 1);
    listen_tiles[0].id = 1; listen_tiles[1] = listen_tiles[0];
    listen_tiles[1].x = get_case(server, 'E', listen_tiles[1].x, 1);
    listen_tiles[1].id = 2; listen_tiles[2] = listen_tiles[1];
    listen_tiles[2].y = get_case(server, 'N', listen_tiles[2].y, 1);
    listen_tiles[2].id = 3; listen_tiles[3] = listen_tiles[2];
    listen_tiles[3].y = get_case(server, 'N', listen_tiles[3].y, 1);
    listen_tiles[3].id = 4; listen_tiles[4] = listen_tiles[3];
    listen_tiles[4].x = get_case(server, 'W', listen_tiles[4].x, 1);
    listen_tiles[4].id = 5; listen_tiles[5] = listen_tiles[4];
    listen_tiles[5].x = get_case(server, 'W', listen_tiles[5].x, 1);
    listen_tiles[5].id = 6; listen_tiles[6] = listen_tiles[5];
    listen_tiles[6].y = get_case(server, 'S', listen_tiles[6].y, 1);
    listen_tiles[6].id = 7; listen_tiles[7] = listen_tiles[6];
    listen_tiles[7].y = get_case(server, 'S', listen_tiles[7].y, 1);
    listen_tiles[7].id = 8;
    return listen_tiles;
}

l_tile *get_east_case(server_t *server, l_tile *listen_tiles)
{
    listen_tiles[0].x = get_case(server, 'E', listen_tiles[0].x, 1);
    listen_tiles[0].id = 1; listen_tiles[1] = listen_tiles[0];
    listen_tiles[1].y = get_case(server, 'N', listen_tiles[1].y, 1);
    listen_tiles[1].id = 2; listen_tiles[2] = listen_tiles[1];
    listen_tiles[2].x = get_case(server, 'W', listen_tiles[2].x, 1);
    listen_tiles[2].id = 3; listen_tiles[3] = listen_tiles[2];
    listen_tiles[3].x = get_case(server, 'W', listen_tiles[3].x, 1);
    listen_tiles[3].id = 4; listen_tiles[4] = listen_tiles[3];
    listen_tiles[4].y = get_case(server, 'S', listen_tiles[4].y, 1);
    listen_tiles[4].id = 5; listen_tiles[5] = listen_tiles[4];
    listen_tiles[5].y = get_case(server, 'S', listen_tiles[5].y, 1);
    listen_tiles[5].id = 6; listen_tiles[6] = listen_tiles[5];
    listen_tiles[6].x = get_case(server, 'E', listen_tiles[6].x, 1);
    listen_tiles[6].id = 7; listen_tiles[7] = listen_tiles[6];
    listen_tiles[7].x = get_case(server, 'E', listen_tiles[7].x, 1);
    listen_tiles[7].id = 8;
    return listen_tiles;
}

l_tile *get_west_case(server_t *server, l_tile *listen_tiles)
{
    listen_tiles[0].x = get_case(server, 'W', listen_tiles[0].x, 1);
    listen_tiles[0].id = 1; listen_tiles[1] = listen_tiles[0];
    listen_tiles[1].y = get_case(server, 'S', listen_tiles[1].y, 1);
    listen_tiles[1].id = 2; listen_tiles[2] = listen_tiles[1];
    listen_tiles[2].x = get_case(server, 'E', listen_tiles[2].x, 1);
    listen_tiles[2].id = 3; listen_tiles[3] = listen_tiles[2];
    listen_tiles[3].x = get_case(server, 'E', listen_tiles[3].x, 1);
    listen_tiles[3].id = 4; listen_tiles[4] = listen_tiles[3];
    listen_tiles[4].y = get_case(server, 'N', listen_tiles[4].y, 1);
    listen_tiles[4].id = 5; listen_tiles[5] = listen_tiles[4];
    listen_tiles[5].y = get_case(server, 'N', listen_tiles[5].y, 1);
    listen_tiles[5].id = 6; listen_tiles[6] = listen_tiles[5];
    listen_tiles[6].x = get_case(server, 'W', listen_tiles[6].x, 1);
    listen_tiles[6].id = 7; listen_tiles[7] = listen_tiles[6];
    listen_tiles[7].x = get_case(server, 'W', listen_tiles[7].x, 1);
    listen_tiles[7].id = 8;
    return listen_tiles;
}