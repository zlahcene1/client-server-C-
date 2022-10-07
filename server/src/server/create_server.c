/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** create_server
*/

#include "server.h"

int create_socket(int port, server_t *s)
{
    int a = 1;

    s->s_serv = socket(AF_INET, SOCK_STREAM, 0);
    if (s->s_serv == -1)
        handle_error("Socket creation failed...");
    if (setsockopt(s->s_serv, SOL_SOCKET, SO_REUSEADDR, &a, sizeof(int)) == -1)
        handle_error("Set Socket creation failed...");
    s->s_adr.sin_family = AF_INET;
    s->s_adr.sin_port = htons(port);
    s->s_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    return EXIT_SUCCESS;
}

int create_bind_listen(server_t *s)
{
    int t = bind(s->s_serv, (struct sockaddr *) &s->s_adr, sizeof(s->s_adr));

    if (t == -1)
        handle_error("Bind failed...");
    if (listen(s->s_serv, SOMAXCONN) == -1)
        handle_error("Listen failed...");
    return EXIT_SUCCESS;
}

int create_accept(server_t *s)
{
    socklen_t lenAddr = sizeof(s->s_adr);
    int socket = accept(s->s_serv, (struct sockaddr *) &s->s_adr, &lenAddr);

    if (socket == -1)
        handle_error("Server accept failed...");
    for (int i = 0; i < CLIENT; i++) {
        if (s->client[i].fd == 0) {
            s->client[i].fd = socket;
            s->client[i].index = 0;
            s->client[i].user = NULL;
            s->client[i].server = s;
            dprintf(s->client[i].fd, "220 Service ready for new user.\r\n");
            break;
        }
    }
    return EXIT_SUCCESS;
}

int set_select(server_t *s)
{
    FD_ZERO(&s->read);
    FD_ZERO(&s->write);
    FD_SET(s->s_serv, &s->read);
    s->max_client = s->s_serv;
    for (int i = 0; i < CLIENT; ++i) {
        if (s->client[i].fd != 0) {
            FD_SET(s->client[i].fd, &s->read);
            FD_SET(s->client[i].fd, &s->write);
        }
        if (s->max_client < s->client[i].fd)
            s->max_client = s->client[i].fd;
    }
    return EXIT_SUCCESS;
}

int create_select(server_t *s)
{
    set_select(s);
    if (select(s->max_client + 1, &s->read, &s->write, NULL, NULL) == -1)
        handle_error("Select failed...");
    if (FD_ISSET(s->s_serv, &s->read))
        create_accept(s);
    for (int i = 0; i < CLIENT; i++) {
        if (FD_ISSET(s->client[i].fd, &s->read) &&
            handle_client(&s->client[i]) == -1) {
            break;
        }
    }
    return EXIT_SUCCESS;
}
