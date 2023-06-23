/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane [WSL: Ubuntu]
** File description:
** teams
*/

#include "../include/server.h"

void generate_teams(server_t *server, struct team_listhead *team_head)
{
    for (int i = 0; i < my_arrlen(server->sname); i++) {
        team_t *team = generate_team(server->sname[i], server->clientsNb);
        LIST_INSERT_HEAD(team_head, team, next);
    }
}

team_t *generate_team(char *name, int maxclient)
{
    team_t *team = malloc(sizeof(team_t));
    team->name = strdup(name);
    team->max_clients = maxclient;
    team->clients = 0;
    return (team);
}
