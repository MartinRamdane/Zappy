/*
** EPITECH PROJECT, 2023
** player.c
** File description:
** player
*/

#include "../include/server.h"

void generate_player(client_t *cli, int socket, char *team_name)
{
    cli->player = malloc(sizeof(player));
    cli->player->x = 0; // TODO: Check if the start position is random or not
    cli->player->y = 0;
    cli->player->level = 1;
    cli->player->inv = malloc(sizeof(inventory));
    cli->player->inv->food = 10;
    cli->player->inv->linemate = 0;
    cli->player->inv->deraumere = 0;
    cli->player->inv->sibur = 0;
    cli->player->inv->mendiane = 0;
    cli->player->inv->phiras = 0;
    cli->player->inv->thystame = 0;
    cli->player->is_dead = 0;
    cli->player->orientation = 'N';
    // TODO add team here
    //cli->player->team_name = strdup(team_name);
    cli->player->socket = socket;
}

void generate_gui_player(client_t *cli, int socket)
{
    cli->gui_player = malloc(sizeof(gui_player));
    cli->gui_player->x = 0;
    cli->gui_player->y = 0;
    cli->gui_player->socket = socket;
}