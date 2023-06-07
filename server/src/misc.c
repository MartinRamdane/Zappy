/*
** EPITECH PROJECT, 2023
** misc.c
** File description:
** misc
*/

#include "../include/server.h"

int *create_tuple(int x, int y)
{
    int *tuple = malloc(sizeof(int) * 2);
    tuple[0] = x;
    tuple[1] = y;
    return (tuple);
}

int check_if_is_resources(char *cmd)
{
    if (strcmp(cmd, "food") == 0)
        return (1);
    if (strcmp(cmd, "linemate") == 0)
        return (2);
    if (strcmp(cmd, "deraumere") == 0)
        return (3);
    if (strcmp(cmd, "sibur") == 0)
        return (4);
    if (strcmp(cmd, "mendiane") == 0)
        return (5);
    if (strcmp(cmd, "phiras") == 0)
        return (6);
    if (strcmp(cmd, "thystame") == 0)
        return (7);
    return (0);
}