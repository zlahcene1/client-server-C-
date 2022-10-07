/*
** EPITECH PROJECT, 2022
** server
** File description:
** users
*/

#include "client.h"

int handle_users_client(client_t *user)
{
    char *tmp = NULL;
    char *tmp2 = NULL;

    tmp = strtok(user->cmd_c, " ");
    tmp = strtok(NULL, "\r\n");
    tmp2 = strtok(tmp, " ");
    tmp2 = strtok(NULL, "\r\n");
    user->uuid = strdup(tmp);
    user->username = strdup(tmp2);
    client_print_users(user->uuid, user->username, user->is_logged);
    return 0;
}

int handle_user_client(client_t *user)
{
    char *tmp = NULL;
    char *tmp2 = NULL;

    tmp = strtok(user->cmd_c, " ");
    tmp = strtok(NULL, "\r\n");
    tmp2 = strtok(tmp, " ");
    tmp2 = strtok(NULL, "\r\n");
    user->uuid = strdup(tmp);
    user->username = strdup(tmp2);
    client_print_user(user->uuid, user->username, user->is_logged);
    return 0;
}