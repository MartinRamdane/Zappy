/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane [WSL: Debian]
** File description:
** orientation_to_number
*/

#include "../include/server.h"

int orientation_to_number(char c)
{
    if (c == 'N')
        return 1;
    if (c == 'E')
        return 2;
    if (c == 'S')
        return 3;
    if (c == 'W')
        return 4;
    return 0;
}
