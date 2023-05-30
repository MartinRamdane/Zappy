/*
** EPITECH PROJECT, 2023
** server.h
** File description:
** server.h
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct server_s {
    int port;
    int width;
    int height;
    char **sname;
    int clientsNb;
    int freq;
} server_t;

void print_help(void);
void fetch_arguments(server_t *s_infos, char **av);