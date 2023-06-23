/*
** EPITECH PROJECT, 2023
** look_command_misc.c
** File description:
** look_command_misc
*/

#include "../include/server.h"

int get_diff_y_per_level(int level, char dir)
{
    if (dir == 'N') {
        return -1 * level;
    }
    if (dir == 'S') {
        return level;
    }
    return 0;
}

int get_diff_x_per_level(int level, char dir)
{
    if (dir == 'W') {
        return -1 * level;
    }
    if (dir == 'E') {
        return level;
    }
    return 0;
}

int get_nb_tiles_per_level(int level)
{
    int value = (level - 1) * 2;
    return (value + 3);
}