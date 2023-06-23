/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "../include/server.h"

static struct option long_options[] = {
    {"port",     required_argument, 0,  'p' },
    {"width",  required_argument,       0,  'x' },
    {"height",  required_argument, 0,  'y' },
    {"name", required_argument,       0,  'n' },
    {"clientsNb",  required_argument, 0, 'c'},
    {"freq",    required_argument, 0,  'f' },
    {0,         0,                 0,  0 }
};

void print_help(void)
{
    printf("USAGE: ./zappy_server -p port -x width -y height -n name1 name2 ");
    printf("... -c clientsNb -f freq\n");
    printf("        port        is the port number\n");
    printf("        width       is the width of the world\n");
    printf("        height      is the height of the world\n");
    printf("        nameX       is the name of the team X\n");
    printf("        clientsNb   is the number of authorized clients per team");
    printf("\n        freq        is the reciprocal of");
    printf(" time unit for execution of actions\n");
}

void fetch_arguments(server_t *s_infos, int arg, char **av, int ac)
{
    switch (arg) {
        case 'p':
            s_infos->port = atoi(optarg); break;
        case 'x':
            s_infos->width = atoi(optarg); break;
        case 'y':
            s_infos->height = atoi(optarg); break;
        case 'n':
            optind--; int i = my_arrlen(s_infos->sname);
            for (ARG_COND){
                s_infos->sname[i] = strdup(av[optind]); i++;
            } break;
        case 'c':
            s_infos->clientsNb = atoi(optarg); break;
        case 'f':
            s_infos->freq = atoi(optarg); break;
        default:
            print_help(); exit(84);
    }
}

int main(int ac, char **av)
{
    int option_index = 0, arg = 0;
    server_t *s_infos = create_server_struct();
    while (arg != -1) {
        arg = getopt_long(ac, av, "p:x:y:n:c:f:", long_options, &option_index);
        if (arg == -1)
            break;
        fetch_arguments(s_infos, arg, av, ac);
    }
    check_args(s_infos); s_infos->game->map = generate_map(s_infos);
    s_infos->game->end = false;
    fill_map(*s_infos, s_infos->game->map); init_server(s_infos);
    char *buffer_respawn = strdup("Respawn");
    double task_time = calculate_time_for_task(s_infos, buffer_respawn);
    add_server_task(s_infos, buffer_respawn, task_time);
    free(buffer_respawn);
    generate_eggs(s_infos); loop_server(s_infos);
    return 0;
}
