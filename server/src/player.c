/*
** EPITECH PROJECT, 2023
** player.c
** File description:
** player
*/

#include "../include/server.h"

void generate_player(server_t *server, client_t *cli, int socket, char *team_name)
{
    cli->player = malloc(sizeof(player));
    cli->player->level = 1;
    cli->player->inv = malloc(sizeof(inventory));
    cli->player->inv->food = 10; cli->player->inv->linemate = 0;
    cli->player->inv->deraumere = 0; cli->player->inv->sibur = 0;
    cli->player->inv->mendiane = 0; cli->player->inv->phiras = 0;
    cli->player->inv->thystame = 0; cli->player->is_dead = 0;
    cli->player->orientation = 'N'; cli->player->id = server->player_id;
    cli->player->team_name = strdup(team_name); cli->player->socket = socket;
    cli->player->state = ALIVE; cli->player->uid = strdup(cli->uid);
    spawn_player_on_egg(cli, server);
}

void generate_gui_player(client_t *cli, int socket, server_t *s_infos)
{
    cli->gui_player = malloc(sizeof(gui_player));
    cli->gui_player->x = 0;
    cli->gui_player->y = 0;
    cli->gui_player->socket = socket;
    send_map_size(cli, s_infos); send_time_unit(cli, s_infos);
    send_map_content(cli, s_infos); send_teams(cli, s_infos);
    send_all_player_pos(cli, s_infos);
}

int check_if_solo_on_tile(server_t *server, client_t *cli)
{
    int _x = cli->player->x; int _y = cli->player->y;
    tile *target = &server->game->map[_x][_y];
    int count = 0;
    t_player_queue *tmp = NULL;
    LIST_FOREACH(tmp, &target->player_head, next) {
        count++;
    }
    if (count > 1)
        return 1;
    printf("solo\n");
    return 0;
}

void add_player_from_queue(tile *tile, player *player)
{
    t_player_queue *p_queue = malloc(sizeof(t_player_queue));
    p_queue->player = player;
    LIST_INSERT_HEAD(&tile->player_head, p_queue, next);
}

void remove_player_from_queue(tile *tile, player *player)
{
    t_player_queue *tmp = NULL;
    LIST_FOREACH(tmp, &tile->player_head, next) {
        if (tmp->player->uid != NULL && strcmp(tmp->player->uid, player->uid) == 0) {
            LIST_REMOVE(tmp, next);
            free(tmp);
            return;
        }
    }
}

player *get_player_from_queue(tile *target, player *player)
{
    t_player_queue *tmp = NULL;
    LIST_FOREACH(tmp, &target->player_head, next) {
        if (strcmp(tmp->player->uid, player->uid) == 0)
            return tmp->player;
    }
    return NULL;
}
