/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane [WSL: Ubuntu]
** File description:
** team_handling
*/

#include "../include/server.h"

int does_team_exists(server_t *s_infos, char *team)
{
    team_t *tmp = NULL;
    LIST_FOREACH(tmp, &s_infos->team_head, next) {
        if (strcmp(tmp->name, team) == 0)
            return (1);
    }
    return (0);
}

int does_team_has_space(server_t *s_infos, char *team)
{
    team_t *tmp = NULL;
    LIST_FOREACH(tmp, &s_infos->team_head, next) {
        if (strcmp(tmp->name, team) == 0) {
            if (tmp->clients < tmp->max_clients)
                return (1);
        }
    }
    return (1);
}

int get_available_slots_in_team(server_t *s_infos, char *team)
{
    team_t *tmp = NULL;
    LIST_FOREACH(tmp, &s_infos->team_head, next) {
        if (strcmp(tmp->name, team) == 0) {
            if (tmp->clients == tmp->max_clients)
                tmp->max_clients++;
            return (tmp->max_clients - tmp->clients);
        }
    }
    return (0);
}

int add_client_to_team(server_t *s_infos, char *team, client_t *cli)
{
    if (strcmp(team, "GRAPHIC") == 0) {
        cli->team_name = strdup(team);
        generate_gui_player(cli, cli->socket, s_infos); return 1;
    }
    if (cli->team_name != NULL) return 0;
    int available_slots = count_all_eggs(s_infos, team);
    char *buff = malloc(sizeof(char) * 100);
    sprintf(buff, "%d\n", available_slots);
    if (does_team_exists(s_infos, team) == 0) return -1;
    if (does_team_has_space(s_infos, team) == 0) {
        send(cli->socket, buff, strlen(buff), 0); return -1;
    }
    team_t *tmp = NULL;
    LIST_FOREACH(tmp, &s_infos->team_head, next) {
        if (strcmp(tmp->name, team) == 0) {
            tmp->clients++; cli->team_name = strdup(team);
            generate_player(s_infos, cli, cli->socket, team);
            char *buffer_life = strdup("LifeCycle");
            double task_food_time = calculate_time_for_task(s_infos, buffer_life);
            add_task(s_infos, buffer_life, task_food_time, cli);
            sprintf(buff, "%d\n%d %d\n", available_slots, s_infos->width, s_infos->height);
            send(cli->socket, buff, strlen(buff), 0);
            send_new_player_connected(s_infos, cli); free(buffer_life);
            free(buff); return 1;
        }
    } free(buff); return 0;
}

void remove_client_from_team(client_t *cli, server_t *s_infos)
{
    if (cli->team_name == NULL) return;
    team_t *tmp = NULL;
    LIST_FOREACH(tmp, &s_infos->team_head, next) {
        if (strcmp(tmp->name, cli->team_name) == 0) {
            tmp->clients--;
            cli->team_name = NULL;
            break;
        }
    }
}
