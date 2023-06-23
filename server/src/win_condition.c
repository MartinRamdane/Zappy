/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane [WSL: Ubuntu]
** File description:
** win_condition
*/

#include "../include/server.h"

team_t *get_nbr_of_lvl_eight_per_team(server_t *server)
{
    team_t *tmp = NULL;
    int count = 0;
    client_t *tmp2 = NULL;
    LIST_FOREACH(tmp, &server->team_head, next) {
        LIST_FOREACH(tmp2, &server->head, next) {
            if (tmp2->player && tmp2->player->level == 8 &&
            strcmp(tmp2->player->team_name, tmp->name) == 0)
                count++;
        }
        if (count >= 6) {
            return tmp;
        } else {
            count = 0;
        }
    }
    return NULL;
}

void send_win_condition_to_gui(server_t *server, team_t *team)
{
    char *buffer = malloc(sizeof(char) * 100);
    sprintf(buffer, "seg %s\n", team->name);
    client_t *tmp = NULL;
    LIST_FOREACH(tmp, &server->head, next) {
        if (tmp->gui_player != NULL) {
            send(tmp->socket, buffer, strlen(buffer), 0);
        }
    }
    free(buffer);
}

void check_win_condition(server_t *server)
{
    team_t *team = get_nbr_of_lvl_eight_per_team(server);
    if (team != NULL) {
        send_win_condition_to_gui(server, team);
        server->game->end = true;
    }
}
