/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** commands
*/

#ifndef _COMMANDS_H_
    #define _COMMANDS_H_

    #include "client.h"
    #include <stddef.h>

typedef struct cmd_s cmd_t;

struct cmd_s {
    char *cmd;
    int (*func)(client_t *);
};

static const cmd_t commands[100] =
{
    {"220 ", &display_connected},
    {"/login ", &handle_login_client},
    {"/logout", &handle_logout_client},
    {"/users", &handle_users_client},
    {"/user ", &handle_user_client},
    {"/send", &handle_send_client},
    {"/messages", &handle_messages_client},
    {NULL, NULL},
};

#endif /* !COMMANDS_H_ */