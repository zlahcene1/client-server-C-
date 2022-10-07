/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** handle_commands
*/

#include "server.h"

int handle_commands(client_t *user)
{
    int i = 0;

    while (commands[i].cmd != NULL) {
        if (!strncmp(commands[i].cmd, user->cmd, strlen(commands[i].cmd))) {
            commands[i].func(user);
            memset(user->cmd, 0, sizeof(user->cmd));
            return EXIT_SUCCESS;
        }
        i++;
    }
    return EXIT_FAILURE;
}