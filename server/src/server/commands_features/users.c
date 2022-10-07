/*
** EPITECH PROJECT, 2022
** server
** File description:
** users
*/

#include "server.h"

void list_all_users(server_t *server)
{
    char uuid_str[UUID_STR_LEN];

    for (int i = 0; i < server->user_count; i++) {
        uuid_unparse(server->users[i].uuid, uuid_str);
        dprintf(server->client->fd, "/users %s %s\r\n", uuid_str,
        server->users[i].username);
    }
}

int handle_users(client_t *client)
{
    list_all_users(client->server);
    return 0;
}

void get_username_from_uuid(server_t *server, char *uuid)
{
    char uuid_str[UUID_STR_LEN];

    for (int i = 0; i < server->user_count; i++) {
        uuid_unparse(server->users[i].uuid, uuid_str);
        if (strcmp(uuid_str, uuid) == 0)
            dprintf(server->client->fd, "/user %s %s\r\n", uuid,
            server->users[i].username);
    }
}

int handle_user(client_t *client)
{
    char *tmp = strtok(client->cmd, " ");

    tmp = strtok(NULL, "\r\n");
    if (counter(client, tmp, '"') == -1)
        return 0;
    tmp = remove_quote(tmp);
    get_username_from_uuid(client->server, tmp);
    return 0;
}