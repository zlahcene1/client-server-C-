/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** main
*/

#include "server.h"

int main(int ac, char **av)
{
    server_t prog = {0};

    if (ac != 2)
        help();
    if (strcmp(av[1], "-h") == 0)
        help();
    is_number(av[1], atoi(av[1]));
    if (ac != 2)
        exit(84);
    else
        core(atoi(av[1]), &prog);
    return EXIT_SUCCESS;
}