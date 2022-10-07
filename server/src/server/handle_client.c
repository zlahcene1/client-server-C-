/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** handle_client
*/

#include "server.h"

int check_crlf(client_t *user)
{
    char *tmp = strstr(user->cmd, "\r\n");

    if (tmp == NULL)
        return EXIT_FAILURE;
    while (tmp != NULL) {
        if (handle_commands(user) == EXIT_FAILURE)
            dprintf(user->fd, "666 Unknown command\r\n");
        memset(user->cmd, 0, tmp + 1 - user->cmd);
        memmove(user->cmd, tmp + 2, strlen(tmp + 2) + 1);
        user->index -= tmp + 2 - user->cmd;
        tmp = strstr(user->cmd, "\r\n");
    }
    return EXIT_FAILURE;
}

int handle_client(client_t *u)
{
    int len = read(u->fd, u->cmd + u->index, sizeof(u->cmd) - u->index - 1);

    if (len == -1)
        handle_error("Read dosent read...");
    else if (len != 0) {
        u->index += len;
        check_crlf(u);
    } else {
        printf("Client [%d] disconnected successfully\r\n", u->fd);
        close(u->fd);
        memset(u, 0, sizeof(client_t));
        return -1;
    }
    return EXIT_SUCCESS;
}