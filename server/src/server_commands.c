/*
** EPITECH PROJECT, 2023
** server_commands.c
** File description:
** server_commands
*/

#include "../include/server.h"

void respawn_task(server_t *server)
{
    respawn_map((*server), server->game->map);
    printf("respawn task executed\n");
    send_map_content_to_all_gui(server);
    char *buffer_respawn = strdup("Respawn");
    double task_time = calculate_time_for_task(server, buffer_respawn);
    add_server_task(server, buffer_respawn, task_time);
}