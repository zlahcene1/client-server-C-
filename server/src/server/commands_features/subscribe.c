/*
** EPITECH PROJECT, 2022
** server
** File description:
** subscribe
*/

#include "server.h"

int handle_subscribe(client_t *user)
{
    printf("/subscribe\n");
    return 0;
}

int handle_subscribed(client_t *user)
{
    printf("/subscribed\n");
    return 0;
}

int handle_unsubscribe(client_t *user)
{
    printf("/unsubscribe\n");
    return 0;
}