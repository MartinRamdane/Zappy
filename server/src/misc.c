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