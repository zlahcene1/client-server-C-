/*
** EPITECH PROJECT, 2022
** server
** File description:
** basic
*/

#include "client.h"

int handle_help_client(client_t *user)
{
    printf("/help\n");
    return 0;
}

int handle_use_client(client_t *user)
{
    printf("/use\n");
    return 0;
}