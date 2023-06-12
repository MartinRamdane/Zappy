/*
** EPITECH PROJECT, 2023
** server_commands.c
** File description:
** server_commands
*/

#include "../include/server.h"

void respawn_task(server_t *server)
{
    printf("respawn of stones\n");
    fill_map(*server, server->game->map);
    debug_print_map(server, server->game->map);
    char *buffer_respawn = strdup("Respawn");
    double task_time = calculate_time_for_task(server, buffer_respawn);
    printf("task time of respawn task: %d\n", task_time);
    add_server_task(server, buffer_respawn, task_time);
}