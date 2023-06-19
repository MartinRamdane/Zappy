/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** timeout
*/

#include "../include/server.h"

task_t *find_task_with_lowest_time(server_t *server)
{
    task_t *tmp = LIST_FIRST(&server->task_head);
    task_t *tmp2 = NULL;
    LIST_FOREACH(tmp2, &server->task_head, next) {
        if (tmp2->time < tmp->time)
            tmp = tmp2;
    }
    return tmp;
}

void calculate_timeout_val(server_t *server)
{
    task_t *tmp = find_task_with_lowest_time(server);
    if (tmp == NULL)
        return;
    server->tv->tv_sec = tmp->time;
    server->tv->tv_usec = (suseconds_t)((tmp->time - (time_t)tmp->time) * 1000000);  // Set the microseconds part
    server->old_timeout = tmp->time;
}

void recalculate_task_time(server_t *server)
{
    task_t *tmp = NULL;
    LIST_FOREACH(tmp, &server->task_head, next) {
        if (tmp->time > 0) {
            struct timeval elapsed_time;
            elapsed_time.tv_sec = server->old_timeout;
            elapsed_time.tv_usec = 0;
            tmp->time -= elapsed_time.tv_sec + (double)elapsed_time.tv_usec / 1000000.0;

            if (tmp->time <= 0) {
                tmp->time = 0;
            }
        }
    }
}



void recalculate_task_time_after_timeout(server_t *server)
{
    task_t *tmp = NULL;
    LIST_FOREACH(tmp, &server->task_head, next) {
        // if (strcmp(tmp->cmd, "LifeCycle") == 0) {
        //     printf("recalc : before : %f\n", tmp->time);
        // }
        tmp->time -= server->old_timeout;
        // if (strcmp(tmp->cmd, "LifeCycle") == 0) {
        //     printf("recalc : after : %f\n", tmp->time);
        // }
    }
}