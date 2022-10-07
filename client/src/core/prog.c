/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** prog
*/

#include "client.h"

int core_client(client_t *user)
{
    create_socket_client(user);
    create_connect(user);
    while (1) {
        if (create_select_client(user) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    free(user->cmd);
    return EXIT_SUCCESS;
}
