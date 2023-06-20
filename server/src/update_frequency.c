/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane [WSL: Debian]
** File description:
** update_frequency
*/

#include "../include/server.h"

void change_time_unit(client_t *cli, server_t *server, char *buff)
{
    strtok(buff, " "); char *time = strtok(NULL, " ");
    if (time == NULL) {
        send(cli->socket, GUI_UNKNOWN_PARAM, strlen(GUI_UNKNOWN_PARAM), 0);
        return;
    }
    server->freq = atoi(time);
    char *buffer = malloc(sizeof(char) * 100); memset(buffer, 0, 100);
    sprintf(buffer, "sst %f\n", server->freq);
    send(cli->socket, buffer, strlen(buffer), 0);
    send_time_unit_to_all_guis(server);
    free(buffer);
}

void send_time_unit_to_all_guis(server_t *server)
{
    client_t *tmp = NULL;
    LIST_FOREACH(tmp, &server->head, next) {
        if (tmp->gui_player != NULL)
            send_time_unit(tmp, server);
    }
}

void update_freq_for_tasks(server_t *server)
{
    task_t *tmp;
    LIST_FOREACH(tmp, &server->task_head, next) {
        double elapsed_time = difftime(time(NULL), tmp->initial_time);
        tmp->time = elapsed_time + calculate_time_for_task(server, tmp->cmd);
    }
}
