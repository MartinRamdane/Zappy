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


void print_help() {
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
    switch(arg) {
        case 'p':
            s_infos->port = atoi(optarg); break;
        case 'x':
            s_infos->width = atoi(optarg); break;
        case 'y':
            s_infos->height = atoi(optarg); break;
        case 'n':
            optind--;
            for (ARG_COND_FOR){
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

int main(int ac, char **av) {
    int option_index = 0, arg = 0;
    server_t *s_infos = create_server_struct();
    while (arg != -1) {
        arg = getopt_long(ac, av, "p:x:y:n:c:f:", long_options, &option_index);
        if (arg == -1)
            break;
        fetch_arguments(s_infos, arg, av, ac);
    }
    check_args(s_infos);
    printf("port: %d\n", s_infos->port);
    printf("width: %d\n", s_infos->width);
    printf("height: %d\n", s_infos->height);
    printf("name: %s\n", s_infos->sname[0]);
    printf("name: %s\n", s_infos->sname[1]);
    printf("name: %s\n", s_infos->sname[2]);
    printf("clientsNb: %d\n", s_infos->clientsNb);
    printf("freq: %d\n", s_infos->freq);
    return 0;
}
