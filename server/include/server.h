/*
** EPITECH PROJECT, 2023
** server.h
** File description:
** server.h
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/queue.h>
#include <dlfcn.h>
#include <errno.h>
#include <stdbool.h>
#include <uuid/uuid.h>
#include <time.h>
#include <math.h>

#define ARG_COND ; optind < ac \
&& av[optind][0] != '-'; optind++
#define MAX_BODY_LENGTH 1024
enum state {
    NONE,
    DEAD,
    FORK,
    EJECT,
    EGG,
};

typedef struct inventory {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} inventory;

typedef struct gui_player {
    int x;
    int y;
    int socket;
} gui_player;

typedef struct egg {
    int x;
    int y;
    int time;
    int level;
    int max_level;
} egg;

typedef struct player {
    char *uuid;
    int x;
    int y;
    int level;
    inventory *inv;
    int is_dead;
    char orientation;
    char *team_name;
    int socket;
} player;

typedef struct tile {
    int x;
    int y;
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
    player *player; // if a player is on the tile
} tile;

typedef struct client {
    int socket;
    char *uid;
    char *buffer;
    char *team_name;
    player *player;
    gui_player *gui_player;
    LIST_ENTRY(client) next;
} client_t;

typedef struct team {
    char *name;
    int max_clients;
    int clients;
} team_t;


typedef struct server_s {
    int port;
    int width;
    int height;
    char **sname;
    int clientsNb;
    int freq;
    int socket;
    client_t *clients;
    team_t *teams; // TODO: Implement teams when the server loads
} server_t;

extern LIST_HEAD(list_head, client) head;

// MISC
void print_help(void);
void fetch_arguments(server_t *s_infos, int arg, char **av, int ac);
void check_args(server_t *s_infos);
int my_arrlen(char **arr);

// SERVER
server_t *create_server_struct(void);
void init_server(server_t *s_infos);
void loop_server(server_t *s_infos);

// CLIENT
void add_client(server_t *s_info);
client_t *generate_client(int socket);
void check_command(client_t *cli);

// MAP
tile **generate_map(server_t *infos);
void fill_map(server_t infos, tile **map);

// MAP RESOURCES
int *get_resources_quantities(int *ratio, server_t infos);
int *get_remaining_resources(int *ratio, server_t infos);
void put_food_resource(server_t infos, tile **map, int r);
void put_linemate_resource(server_t infos, tile **map, int r);
void put_deraumere_resource(server_t infos, tile **map, int r);
void put_sibur_resource(server_t infos, tile **map, int r);
void put_mendiane_resource(server_t infos, tile **map, int r);
void put_phiras_resource(server_t infos, tile **map, int r);
void put_thystame_resource(server_t infos, tile **map, int r);

// CMD
void move_player(player *p, tile **map, int x, int y);

// DEBUG
void debug_print_map(server_t *s_infos, tile **map);
