/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** handle_commands
*/

#include "commands_client.h"

int display_connected(client_t *user)
{
    printf("%s", user->cmd_c);
    return 0;
}

int check_crlf(client_t *user)
{
    char *tmp = strstr(user->cmd_c, "\r\n");

    if (tmp == NULL)
        return EXIT_FAILURE;
    while (tmp != NULL) {
        if (handle_commands(user) == EXIT_FAILURE)
            printf("666 Invalid commands\r\n");
        memset(user->cmd_c, 0, tmp + 1 - user->cmd_c);
        memmove(user->cmd_c, tmp + 2, strlen(tmp + 2) + 1);
        user->index -= tmp + 2 - user->cmd_c;
        tmp = strstr(user->cmd_c, "\r\n");
    }
    return EXIT_FAILURE;
}

int handle_commands(client_t *user)
{
    int i = 0;

    while (commands[i].cmd != NULL) {
        if (!strncmp(commands[i].cmd, user->cmd_c, strlen(commands[i].cmd))) {
            commands[i].func(user);
            memset(user->cmd_c, 0, sizeof(user->cmd_c));
            return EXIT_SUCCESS;
        }
        i++;
    }
    return EXIT_FAILURE;
}
