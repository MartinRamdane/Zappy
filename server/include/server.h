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
#define GUI_UNKNOWN_PARAM "sbp\n"
enum state {
    DEAD,
    EGG,
    INCANTATION,
    ALIVE,
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
    int id;
    int parent_id;
    char *team_name;
    bool is_default;
    LIST_ENTRY(egg) next;
} t_egg;

typedef struct player {
    int x;
    int y;
    int level;
    inventory *inv;
    int is_dead;
    char orientation;
    char *team_name;
    int socket;
    enum state state;
    char *uid;
    int id;
} player;

typedef struct player_queue {
    player *player;
    LIST_ENTRY(player_queue) next;
} t_player_queue;

extern LIST_HEAD(player_listhead, player_queue) player_head;
extern LIST_HEAD(eggs_list, egg) eggs_head;

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
    struct player_listhead player_head;
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
    LIST_ENTRY(team) next;
} team_t;

extern LIST_HEAD(list_head, client) head;
extern LIST_HEAD(team_listhead, team) team_head;
typedef struct game {
    tile **map;
    bool end;
} game_t;

typedef struct task {
    char *cmd;
    int id;
    double time;
    client_t *client;
    double initial_time;
    LIST_ENTRY(task) next;
} task_t;
extern LIST_HEAD(task_listhead, task) task_head;

typedef struct server_s {
    int port;
    int width;
    int height;
    char **sname;
    int clientsNb;
    double freq;
    int socket;
    int task_id;
    int task_stack;
    int player_id;
    int egg_id;
    struct list_head head;
    struct team_listhead team_head;
    struct task_listhead task_head;
    struct timeval *tv;
    double old_timeout;
    struct eggs_list eggs_head;
    client_t *clients;
    game_t *game;
    task_t *tasks;
    team_t *teams; // TODO: Implement teams when the server loads
} server_t;

typedef struct listen_tile {
    int x;
    int y;
    int id;
    player *player;
} l_tile;


// MISC
void print_help(void);
void fetch_arguments(server_t *s_infos, int arg, char **av, int ac);
void check_args(server_t *s_infos);
int my_arrlen(char **arr);
int *create_tuple(int x, int y);
int get_diff_y_per_level(int level, char dir);
int get_diff_x_per_level(int level, char dir);
int get_nb_tiles_per_level(int level);
int check_if_is_resources(char *cmd);
char *generate_uuid(void);
void remove_player_from_tile(client_t *cli, server_t *s_infos);
void remove_client(int socket, server_t *s_infos);
l_tile *get_north_case(server_t *server, l_tile *listen_tiles);
l_tile *get_south_case(server_t *server, l_tile *listen_tiles);
l_tile *get_east_case(server_t *server, l_tile *listen_tiles);
l_tile *get_west_case(server_t *server, l_tile *listen_tiles);
int get_nb_players_on_tile(tile *tile);
int check_can_incantation(server_t *server, client_t *client);
void update_incantation(server_t *server, client_t *client);
void update_incantation_2(client_t *client, tile *_tile, server_t *server);
void update_incantation_3(client_t *client, tile *_tile, server_t *server);
void make_incantation_for_all_players(server_t *server, client_t *client);
void remove_incantation_task_for_player(server_t *server, client_t *client);

// SERVER
server_t *create_server_struct(void);
void init_server(server_t *s_infos);
void add_client(server_t *s_infos);
void loop_server(server_t *s_infos);

// CLIENT
void add_client(server_t *s_infos);
client_t *generate_client(int socket);
void check_command(client_t *cli, server_t *s_infos);
void handle_client_data(server_t *s_infos, fd_set *readfds);
void generate_teams(server_t *server, struct team_listhead *team_head);
team_t *generate_team(char *name, int maxclient);
int commands(server_t *server, client_t *client, char *buffer);
int add_client_to_team(server_t *s_infos, char *team, client_t *cli);
int get_available_slots_in_team(server_t *s_infos, char *team);
int does_team_has_space(server_t *s_infos, char *team);
int does_team_exists(server_t *s_infos, char *team);
void remove_client_from_team(client_t *cli, server_t *s_infos);
void life_cycle_command(server_t *server, client_t *client);

// MAP
tile **generate_map(server_t *infos);
void fill_map(server_t infos, tile **map);
void respawn_map(server_t infos, tile **map);
void respawn_map_2(server_t infos, tile **map, int *resources);

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
void respawn_task(server_t *server);
int *take_all_resources_from_map(server_t infos);

// TASK
void add_task(server_t *server, char *cmd, double time, client_t *cli);
void execute_tasks(server_t *server);
void send_task_response(server_t *server, task_t *task, char *cmd);
void forward_command(server_t *server, client_t *client);
void right_command(client_t *client);
void left_command(client_t *client);
bool check_task_nb(server_t *server, client_t *client);
void inventory_command(client_t *client);
void look_command(server_t *server, client_t *client);
void set_command(server_t *server, client_t *client, char *buffer);
void take_command(server_t *server, client_t *client, char *buffer);
void eject_command(server_t *server, client_t *client);
void broadcast_command(server_t *server, client_t *client, char *msg);
void incantation_command(client_t *client, server_t *server);
void remove_task_of_player(client_t *cli, server_t *s_infos);
void update_freq_for_tasks(server_t *server);
void add_server_task(server_t *server, char *cmd, double t_time);

// CMD
void move_player(player *p, tile **map, int *pos, server_t *s_infos);
int get_case(server_t *server, char dir, int tile, int diff);
int get_nb_tiles_per_level(int level);
int get_first_case_id_per_level(server_t *server, int tile, char dir, int level);
char *get_all_tile_infos(tile *target);
char *get_all_tiles_per_level(server_t *server, client_t *client, int level);
int set_object(server_t *server, client_t *client, char *buffer);
int take_object(server_t *server, client_t *client, char *buffer);
void eject_all_players(server_t *server, client_t *client, int x, int y);
int eject_player(server_t *server, client_t *client);
int check_instant_commands(char *buffer, client_t *client, server_t *server);
l_tile *get_all_listen_tiles_position(server_t *server, player *player);
int *compare_diff(int **diff);
int compare_listen_tiles(l_tile *listen_tiles, int x, int y);
void send_broadcast(server_t *server, client_t *sender, client_t *client, char *msg);

// PLAYER
void generate_player(server_t *server, client_t *cli, int socket, char *team_name);
void generate_gui_player(client_t *cli, int socket, server_t *s_infos);
int check_if_solo_on_tile(server_t *server, client_t *cli);
void add_player_from_queue(tile *tile, player *player);
void remove_player_from_queue(tile *tile, player *player);

// DEBUG
void debug_print_map(server_t *s_infos, tile **map);
void debug_print_gui_player(client_t *cli);
void debug_print_player(client_t *cli);
void debug_print_task_queue(server_t *server);
void debug_print_player_inventory(client_t *cli);

//TIME
double calculate_time_for_task(server_t *server, char *buffer);
void change_time_unit(client_t *cli, server_t *server, char *buff);
task_t *find_task_with_lowest_time(server_t *server);
void calculate_timeout_val(server_t *server);
void recalculate_task_time(server_t *server);
void recalculate_task_time_after_timeout(server_t *server);

//GUI COMMANDS
int check_gui_commands(char *buffer, client_t *client, server_t *server);
void send_map_size(client_t *client, server_t *server);
void send_time_unit(client_t *client, server_t *server);
void send_teams(client_t *client, server_t *server);
void send_tile_content(client_t *client, server_t *server, char *msg);
void send_tile_with_pos(client_t *client, server_t *server, int x, int y);
void send_map_content(client_t *client, server_t *server);
void send_tile_with_pos(client_t *client, server_t *server, int x, int y);
void send_new_player_connected(server_t *server, client_t *player);
void send_playerdata_to_gui(client_t *cli, client_t *pl);
void send_player_pos(client_t *cli, server_t *server, char *buff);
int check_others_gui_cmd(char *buffer, client_t *client, server_t *server);
void send_player_level(client_t *cli, server_t *server, char *buff);
void send_player_inventory(client_t *cli, server_t *server, char *buff);
int orientation_to_number(char c);
void send_new_player_pos(client_t *cli, server_t *server);
void event_player_expulsion(client_t *cli, server_t *server);
void event_player_broadcast(client_t *cli, server_t *server, char *msg);
void event_player_incantation_start(client_t *cli, server_t *server);
void event_player_incantation_end(client_t *cli, server_t *server, int res);
void send_ressource_collect(client_t *cli, int ressource, server_t *server);
void send_ressource_dropped(client_t *cli, int ressource, server_t *server);
void send_map_content_to_all_gui(server_t *server);
void event_end_of_game(server_t *server, team_t *winners);
void send_all_player_pos(client_t *cli, server_t *server);
void send_time_unit_to_all_guis(server_t *server);
void send_player_death(client_t *player, server_t *server);
void send_new_egg_to_guis(server_t *server, t_egg *egg);
void send_egg_death_to_guis(server_t *server, t_egg *egg);

//FORK
void fork_command(client_t *client, server_t *server);
void remove_eggs_on_tile(server_t *server, int x, int y);

//EGGS
void generate_eggs(server_t *s_infos);
void spawn_player_on_egg(client_t *cli, server_t *server);
void send_egg_connection_to_guis(server_t *server, t_egg *egg);
int count_default_eggs(server_t *s_infos, char *team);
void regenerate_eggs(server_t *s_infos);
int count_all_eggs(server_t *s_infos, char *team);

//WIN
team_t *get_nbr_of_lvl_eight_per_team(server_t *server);
void send_win_condition_to_gui(server_t *server, team_t *team);
void check_win_condition(server_t *server);
