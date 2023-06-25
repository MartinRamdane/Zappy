/*
** EPITECH PROJECT, 2023
** task.c
** File description:
** task
*/

#include "../include/server.h"

void add_task(server_t *server, char *cmd, double t_time, client_t *cli)
{
    if (check_task_nb(server, cli) == false) return;
    if (strcmp(cmd, "Incantation") == 0) {
        event_player_incantation_start(cli, server);
        cli->player->state = INCANTATION;
        if (check_can_incantation(server, cli) == 0) {
            send(cli->socket, "ko\n", 3, 0);
        } else
            send(cli->socket, "Elevation underway\n", 19, 0);
    }
    task_t *new_task = malloc(sizeof(task_t));
    new_task->cmd = strdup(cmd); new_task->time = t_time;
    new_task->id = server->task_id; server->task_id++;
    new_task->initial_time = time(NULL); new_task->client = cli;
    new_task->next.le_next = NULL;
    if (LIST_EMPTY(&server->task_head)) {
        LIST_INSERT_HEAD(&server->task_head, new_task, next); return;
    }
    task_t *tmp;
    LIST_FOREACH(tmp, &server->task_head, next) {
        if (tmp->next.le_next == NULL) {
            LIST_INSERT_AFTER(tmp, new_task, next); break;
        }
    }
}

void add_server_task(server_t *server, char *cmd, double t_time)
{
    task_t *new_task = malloc(sizeof(task_t));
    new_task->cmd = strdup(cmd); new_task->time = t_time;
    new_task->id = server->task_id; server->task_id++;
    new_task->initial_time = time(NULL); new_task->client = NULL;
    new_task->next.le_next = NULL;
    if (LIST_EMPTY(&server->task_head)) {
        LIST_INSERT_HEAD(&server->task_head, new_task, next); return;
    }
    task_t *tmp;
    LIST_FOREACH(tmp, &server->task_head, next) {
        if (tmp->next.le_next == NULL) {
            LIST_INSERT_AFTER(tmp, new_task, next); break;
        }
    }
}

bool check_task_nb(server_t *server, client_t *client)
{
    int counter = 0;
    task_t *tmp;
    LIST_FOREACH(tmp, &server->task_head, next) {
        if (tmp->client != NULL && tmp->client->socket == client->socket) {
            counter++;
        }
    }
    if (counter < 10) {
        return true;
    }
    return false;
}

double calculate_time_for_task(server_t *server, char *buffer)
{
    if (strcmp(buffer, "Forward") == 0) return (7.0 / server->freq);
    else if (strcmp(buffer, "Right") == 0) return (7.0 / server->freq);
    else if (strcmp(buffer, "Left") == 0) return (7.0 / server->freq);
    else if (strcmp(buffer, "Look") == 0) return (7.0 / server->freq);
    else if (strcmp(buffer, "Inventory") == 0)
        return (1.0 / server->freq);
    else if (strstr(buffer, "Broadcast")) return (7.0 / server->freq);
    else if (strcmp(buffer, "Fork") == 0) return (42.0 / server->freq);
    else if (strcmp(buffer, "Eject") == 0) return (7.0 / server->freq);
    else if (strstr(buffer, "Take")) return (7.0 / server->freq);
    else if (strstr(buffer, "Set")) return (7.0 / server->freq);
    else if (strcmp(buffer, "Incantation") == 0)
        return (300.0 / server->freq);
    else if (strcmp(buffer, "Respawn") == 0)
        return (20.0 / server->freq);
    else if (strcmp(buffer, "LifeCycle") == 0)
        return (126.0 / server->freq);
    else return 0.0;
}

void execute_tasks(server_t *server)
{
    if (server->game->end)
        return;
    task_t *tmp = NULL;
    LIST_FOREACH(tmp, &server->task_head, next) {
        if (tmp->time <= 0) {
                send_task_response(server, tmp, tmp->cmd);
                LIST_REMOVE(tmp, next);
        }
    }
    return;
}