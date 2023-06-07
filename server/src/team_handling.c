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
    return (1); //TODO : Enforce team size limit
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
        cli->team_name = strdup(team); generate_gui_player(cli, cli->socket);
        send_map_size(cli, s_infos); send_time_unit(cli, s_infos);
        send_map_content(cli, s_infos); send_teams(cli, s_infos); return 1;
    }
    if (cli->team_name != NULL) return 0;
    int available_slots = get_available_slots_in_team(s_infos, team) - 1;
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
            send(cli->socket, buff, strlen(buff), 0);
            generate_player(s_infos, cli, cli->socket, team);
            sprintf(buff, "%d %d\n", s_infos->width, s_infos->height);
            send(cli->socket, buff, strlen(buff), 0);
            send_new_player_connected(s_infos, cli); return 1;
        }
    } return 0;
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
