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
#include <getopt.h>

#define ARG_COND_FOR int i = my_arrlen(s_infos->sname); optind < ac && \
av[optind][0] != '-'; optind++

typedef struct server_s {
    int port;
    int width;
    int height;
    char **sname;
    int clientsNb;
    int freq;
} server_t;

void print_help();
void fetch_arguments(server_t *s_infos, int arg, char **av, int ac);
void check_args(server_t *s_infos);
server_t *create_server_struct(void);
int my_arrlen(char **arr);
