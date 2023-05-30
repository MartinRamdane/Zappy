/*
** EPITECH PROJECT, 2023
** server.c
** File description:
** server
*/

#include "../include/server.h"

struct list_head head;

void init_server(server_t *s_infos)
{
    struct client *tmp = NULL; LIST_INIT(&head);
    s_infos->socket = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(s_infos->socket, 1, 2, &(int){1}, sizeof(int));
    struct sockaddr_in myaddr;
    myaddr.sin_family = AF_INET; inet_aton("0.0.0.0", &myaddr.sin_addr);
    myaddr.sin_port = htons(s_infos->port);
    bind(s_infos->socket, (struct sockaddr *)&myaddr, sizeof(myaddr));
    listen(s_infos->socket, s_infos->clientsNb);
}

void add_client(server_t *s_info)
{
    struct sockaddr_in clientaddr; int addrlen = sizeof(clientaddr);
    int new_client = accept(s_info->socket,
    (struct sockaddr *)&clientaddr, (socklen_t *)&addrlen);
    if (new_client < 0) {
        perror("accept");
        exit(84);
    } else {
        printf("New client connected\n");
    }
    client_t *cli = generate_client(new_client);
    LIST_INSERT_HEAD(&head, cli, next);
}

void add_clients_to_set(fd_set *set, server_t *s_infos)
{

    struct client *tmp = NULL;
    LIST_FOREACH(tmp, &head, next) {
        if (tmp->socket != -1)
            FD_SET(tmp->socket, set);
    }
}

void loop_server(server_t *s_infos)
{
    while (1) {
        fd_set readfds; FD_ZERO(&readfds);
        FD_SET(s_infos->socket, &readfds);
        add_clients_to_set(&readfds, s_infos);
        int select_val = select(1000, &readfds, NULL, NULL, NULL);
        if (select_val <= 0) {
            
        }    // Erreur / timeout sur le select
        if (FD_ISSET(s_infos->socket, &readfds)) {
            add_client(s_infos);
        } else {
            handle_client_data(s_infos, &readfds);
        }
    }
}