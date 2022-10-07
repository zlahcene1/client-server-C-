/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** utils
*/

#include "server.h"

int is_number(char *av, int port)
{
    for (int i = 0; av[i] != '\0'; i++) {
        if (port < 0 || port > 65536) {
            printf("%d: Bad port, must be between 0 and 65536\r\n", port);
            exit(84);
        }
        if (av[i] < '0' || av[i] > '9') {
            printf("%s: Bad port, must be a int between 0 and 65536\r\n", av);
            exit(84);
        }
    }
    return EXIT_SUCCESS;
}

int handle_error(const char *msg)
{
    do {
        perror(msg);
        exit(84);
    } while (0);
}

void help(void)
{
    printf("USAGE: ./myteams_server port\n\n\t");
    printf("port is the port number on which the server socket listens.\n");
    exit(0);
}

int counter(client_t *client, char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            count++;
    if (count != 2)
        return -1;
    return count;
}

char *remove_quote(char *tmp)
{
    for (int i = 0; tmp[i]; i++) {
        if (tmp[i] == '"') {
            tmp += 1;
            tmp[strlen(tmp) - 1] = '\0';
            return tmp;
        }
    }
    return NULL;
}