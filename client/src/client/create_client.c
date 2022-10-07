/*
** EPITECH PROJECT, 2022
** client
** File description:
** create_client
*/

#include "client.h"

void create_socket_client(client_t *user)
{
    if ((user->s_client = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        handle_error("Error : socket");
    user->adr.sin_family = AF_INET;
    user->adr.sin_port = htons(user->port);
    user->adr.sin_addr.s_addr = htonl(INADDR_ANY);
}

void create_connect(client_t *u)
{
    int c = connect(u->s_client, (struct sockaddr *)&u->adr, sizeof(u->adr));

    if (c == -1)
        handle_error("Error : connect");
}

static void create_send(client_t *user)
{
    ssize_t send = dprintf(user->s_client, "%s\r\n", user->cmd);

    if (send == -1)
        handle_error("Error : write");
}

static void create_read(client_t *u)
{
    int l = 0;

    l = read(u->s_client, u->cmd_c + u->index, sizeof(u->cmd_c) - u->index - 1);
    if (l == -1)
        handle_error("Error : read");
    u->index += l;
}

int create_select_client(client_t *user)
{
    FD_ZERO(&user->read);
    FD_ZERO(&user->write);
    FD_SET(user->s_client, &user->read);
    FD_SET(0, &user->read);
    if (select(user->s_client + 1, &user->read, &user->write, NULL, NULL) == -1)
        handle_error("Select failed...");
    if (FD_ISSET(user->s_client, &user->read)) {
        create_read(user);
        check_crlf(user);
    }
    if (FD_ISSET(0, &user->read)) {
        user->cmd = malloc(sizeof(char) * 1024);
        if (read(0, user->cmd, 1024) == -1)
            handle_error("Error : read");
        create_send(user);
        free(user->cmd);
    }
    return EXIT_SUCCESS;
}