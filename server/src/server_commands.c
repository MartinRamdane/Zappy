/*
** EPITECH PROJECT, 2023
** server_commands.c
** File description:
** server_commands
*/

#include "../include/server.h"

void respawn_task(server_t *server)
{
    fill_map(*server, server->game->map);
    char *buffer_respawn = strdup("Respawn");
    double task_time = calculate_time_for_task(server, buffer_respawn);
    add_server_task(server, buffer_respawn, task_time);
}