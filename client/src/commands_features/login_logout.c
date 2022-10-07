/*
** EPITECH PROJECT, 2022
** server
** File description:
** login_logout
*/

#include "client.h"

int handle_login_client(client_t *user)
{
    char *tmp = NULL;
    char *tmp2 = NULL;

    tmp = strtok(user->cmd_c, " ");
    tmp = strtok(NULL, "\r\n");
    tmp2 = strtok(tmp, " ");
    tmp2 = strtok(NULL, "\r\n");
    user->uuid = strdup(tmp);
    user->username = strdup(tmp2);
    user->is_logged = true;
    client_event_logged_in(user->uuid, user->username);
    return 0;
}

int handle_logout_client(client_t *user)
{
    user->is_logged = false;
    client_event_logged_out(user->uuid, user->username);
    return 0;
}