/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** prog
*/

#include "server.h"

int core(int port, server_t *s)
{
    s->user_count = 0;
    create_socket(port, s);
    create_bind_listen(s);
    while (1) {
        create_select(s);
    }
    close(s->s_serv);
    return EXIT_SUCCESS;
}