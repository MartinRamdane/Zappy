/*
** EPITECH PROJECT, 2023
** task.c
** File description:
** task
*/

#include "../include/server.h"

void add_task(server_t *server, char *cmd, int time)
{
    task_t *new_task = malloc(sizeof(task_t));
    new_task->cmd = strdup(cmd);
    new_task->time = time;
    new_task->id = server->task_id;
    server->task_id++;
    new_task->next.le_next = NULL;
    if (LIST_EMPTY(&server->task_head)) {
        LIST_INSERT_HEAD(&server->task_head, new_task, next);
        return;
    }
    task_t *tmp;
    LIST_FOREACH(tmp, &server->task_head, next) {
        if (tmp->next.le_next == NULL) {
            LIST_INSERT_AFTER(tmp, new_task, next);
            break;
        }
    }
}


void remove_first_task(server_t *server)
{
    if (LIST_EMPTY(&server->task_head)) {
        return;
    }

    task_t *first_task = LIST_FIRST(&server->task_head);
    LIST_REMOVE(first_task, next);
}

