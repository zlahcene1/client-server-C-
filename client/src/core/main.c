/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** main
*/

#include "client.h"

int main(int ac, char **av)
{
    client_t program = {0};

    if (ac == 2 && strcmp(av[1], "-help") == 0)
        help();
    if (ac != 3)
        return 84;
    program.ip = av[1];
    program.port = atoi(av[2]);
    return core_client(&program) == EXIT_SUCCESS ? 0 : 84;
}
