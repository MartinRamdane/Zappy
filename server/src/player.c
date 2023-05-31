/*
** EPITECH PROJECT, 2023
** player.c
** File description:
** player
*/

#include "../include/server.h"

void generate_player(client_t *cli, int socket, char *team_name)
{
    player *new_player = malloc(sizeof(player));
    new_player->x = rand() % 10; // TODO: Check if the start position is random or not
    new_player->y = rand() % 10;
    new_player->level = 1;
    new_player->inv = malloc(sizeof(inventory));
    new_player->inv->food = 10;
    new_player->inv->linemate = 0;
    new_player->inv->deraumere = 0;
    new_player->inv->sibur = 0;
    new_player->inv->mendiane = 0;
    new_player->inv->phiras = 0;
    new_player->inv->thystame = 0;
    new_player->is_dead = 0;
    new_player->orientation = 'N';
    new_player->team_name = strdup(team_name);
    new_player->socket = socket;
    cli->player = new_player;
}

void generate_gui_player(client_t *cli, int socket)
{
    gui_player *new_gui_player = malloc(sizeof(gui_player));
    new_gui_player->x = cli->player->x;
    new_gui_player->y = cli->player->y;
    new_gui_player->socket = socket;
    cli->gui_player = new_gui_player;
}