/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** commands
*/

#ifndef _COMMANDS_H_
    #define _COMMANDS_H_

    #include "users.h"
    #include <stddef.h>

typedef struct cmd_s cmd_t;

struct cmd_s {
    char *cmd;
    int (*func)(client_t *);
};

static const cmd_t commands[100] =
{
    {"/help", &handle_help},
    {"/login ", &handle_login},
    {"/logout", &handle_logout},
    {"/users", &handle_users},
    {"/user ", &handle_user},
    {"/send ", &handle_send},
    {"/messages ", &handle_messages},
    {"/subscribe ", &handle_subscribe},
    {"/subscribed ", &handle_subscribed},
    {"/unsubscribe ", &handle_unsubscribe},
    {"/use ", &handle_use},
    {"/create ", &handle_create},
    {"/list ", &handle_list},
    {"/info ", &handle_info},
    {NULL, NULL},
};

#endif /* !COMMANDS_H_ */
