/*
** EPITECH PROJECT, 2022
** server
** File description:
** login_logout
*/

#include "server.h"

user_t *find_user(server_t *server, char *username)
{
    for (int i = 0; i < server->user_count; i++)
        if (strcmp(server->users[i].username, username) == 0)
            return &server->users[i];
    return NULL;
}

user_t *create_user(server_t *server, char *username)
{
    char uuid_str[UUID_STR_LEN];

    for (int i = 0; i < CLIENT; i++) {
        if (server->users[i].username == NULL) {
            server->users[i].username = strdup(username);
            uuid_generate(server->users[i].uuid);
            uuid_unparse(server->users[i].uuid, uuid_str);
            server->user_count++;
            server_event_user_created(uuid_str, server->users[i].username);
            server->users[i].is_logged = true;
            return &server->users[i];
        }
    }
    return NULL;
}

int handle_login(client_t *client)
{
    char *tmp = strtok(client->cmd, " ");
    char uuid[UUID_STR_LEN];

    tmp = strtok(NULL, "\r\n");
    if (counter(client, tmp, '"') == -1)
        return 0;
    tmp = remove_quote(tmp);
    if (client->user == NULL) {
        client->user = find_user(client->server, tmp);
        if (client->user == NULL) {
            client->user = create_user(client->server, tmp);
            if (client->user == NULL)
                return handle_error("User creation failed");
        }
        uuid_unparse(client->user->uuid, uuid);
        server_event_user_logged_in(uuid);
        dprintf(client->fd, "/login %s %s\r\n", uuid, client->user->username);
    } else
        dprintf(client->fd, "/login already connected\r\n");
    return 0;
}

void handle_logout_client(server_t *server)
{
    for (int i = 0; i < server->user_count; i++)
        server->users[i].is_logged = false;
}

int handle_logout(client_t *client)
{
    char uuid_str[UUID_STR_LEN];

    if (client->user != NULL) {
        handle_logout_client(client->server);
        dprintf(client->fd, "/logout\r\n");
        uuid_unparse(client->user->uuid, uuid_str);
        server_event_user_logged_out(uuid_str);
        client->user = NULL;
    } else
        printf("/logout not logged in\r\n");
    return 0;
}