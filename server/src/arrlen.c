/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** my_arrlen
*/

#include "../include/server.h"

int my_arrlen(char **arr)
{
    int i = 0;
    while (arr[i] != NULL)
        i++;
    return i;
}
