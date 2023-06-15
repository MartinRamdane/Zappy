/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane [WSL: Ubuntu]
** File description:
** handle_received_data
*/

#include "../include/server.h"

int check_is_ai_commands(char *buffer)
{
    if (strcmp(buffer, "Forward") == 0) return 1;
    else if (strcmp(buffer, "Right") == 0) return 1;
    else if (strcmp(buffer, "Left") == 0) return 1;
    else if (strcmp(buffer, "Look") == 0) return 1;
    else if (strcmp(buffer, "Inventory") == 0) return 1;
    else if (strstr(buffer, "Broadcast")) return 1;
    else if (strcmp(buffer, "Fork") == 0) return 1;
    else if (strcmp(buffer, "Eject") == 0) return 1;
    else if (strstr(buffer, "Take")) return 1;
    else if (strstr(buffer, "Set")) return 1;
    else if (strcmp(buffer, "Incantation") == 0) return 1;
    else return 0;
}

int check_instant_commands(char *buffer, client_t *client, server_t *server)
{
    if (strcmp(buffer, "Connect_nbr") == 0) {
        int nb = count_all_eggs(server, client->team_name);
        char *buff = malloc(sizeof(char) * 100);
        memset(buff, 0, 100);
        sprintf(buff, "%d\n", nb);
        send(client->socket, buff, strlen(buff), 0);
        free(buff);
        return 1;
    }
    return 0;
}

int commands(server_t *server, client_t *client, char *buffer)
{
    if (add_client_to_team(server, buffer, client) != 0)
        return 0;
    if (check_instant_commands(buffer, client, server) == 1)
        return 0;
    if (check_gui_commands(buffer, client, server) == 1)
        return 0;
    if (check_is_ai_commands(buffer) == 1) {
        double task_time = calculate_time_for_task(server, buffer);
        add_task(server, buffer, task_time, client);
    } else {
        send(client->socket, "ko\n", 3, 0);
        printf("no AI command\n"); // TODO: Implement GUI commands
    }
    return 0;
}