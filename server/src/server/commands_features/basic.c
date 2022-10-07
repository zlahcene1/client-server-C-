/*
** EPITECH PROJECT, 2022
** server
** File description:
** basic
*/

#include "server.h"

int handle_help(client_t *user)
{
    printf("/help\n");
    return 0;
}

int handle_use(client_t *user)
{
    printf("/use\n");
    return 0;
}