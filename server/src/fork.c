/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane [WSL: Ubuntu]
** File description:
** fork
*/

#include "../include/server.h"

void remove_eggs_on_tile(server_t *server, int x, int y)
{
    t_egg *tmp = NULL;
    LIST_FOREACH(tmp, &server->eggs_head, next) {
        if (tmp->x == x && tmp->y == y) {
            LIST_REMOVE(tmp, next);
            free(tmp);
        }
    }
}