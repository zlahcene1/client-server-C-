/*
** EPITECH PROJECT, 2022
** client
** File description:
** utils
*/

#include "client.h"

int handle_error(const char *msg)
{
    do {
        perror(msg);
        exit(84);
    } while (0);
}

void help(void)
{
    printf("USAGE: ./myteams_cli ip port\n\t");
    printf("ip is the server ip address on which the server socket listens\n");
    printf("\tport is the port number on which the server socket listens\n");
    exit(0);
}