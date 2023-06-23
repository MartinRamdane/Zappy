/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane [WSL: Ubuntu]
** File description:
** eggs
*/

#include "../include/server.h"

void generate_eggs(server_t *s_infos)
{
    team_t *tmp = NULL;
    LIST_FOREACH(tmp, &s_infos->team_head, next) {
        for (int i = 0; i < s_infos->clientsNb; i++) {
            t_egg *egg = malloc(sizeof(t_egg));
            egg->team_name = tmp->name;
            egg->x = rand() % s_infos->width;
            egg->y = rand() % s_infos->height;
            egg->id = s_infos->egg_id; s_infos->egg_id++;
            egg->is_default = true;
            egg->parent_id = -1;
            LIST_INSERT_HEAD(&s_infos->eggs_head,
            egg, next);
        }
    }
}

void regenerate_eggs(server_t *s_infos)
{
    team_t *tmp = NULL;
    LIST_FOREACH(tmp, &s_infos->team_head, next) {
        int counter = count_default_eggs(s_infos, tmp->name);
        if (counter != s_infos->clientsNb) {
            for (int i = 0; i < s_infos->clientsNb - counter; i++) {
                t_egg *egg = malloc(sizeof(t_egg));
                egg->team_name = tmp->name;
                egg->x = rand() % s_infos->width;
                egg->y = rand() % s_infos->height;
                egg->id = s_infos->egg_id; s_infos->egg_id++;
                egg->is_default = true;
                egg->parent_id = -1;
                LIST_INSERT_HEAD(&s_infos->eggs_head,
                egg, next);
            }
        }
    }
}

int count_default_eggs(server_t *s_infos, char *team)
{
    t_egg *egg = NULL;
    int count = 0;
    LIST_FOREACH(egg, &s_infos->eggs_head, next) {
        if (strcmp(egg->team_name, team) == 0 && egg->is_default) {
            count++;
        }
    }
    return count;
}

int count_all_eggs(server_t *s_infos, char *team)
{
    t_egg *egg = NULL;
    int count = 0;
    LIST_FOREACH(egg, &s_infos->eggs_head, next) {
        if (strcmp(egg->team_name, team) == 0) {
            count++;
        }
    }
    return count;
}