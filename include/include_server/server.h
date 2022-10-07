/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** server
*/

#ifndef _SERVER_H_
    #define _SERVER_H_

    #define _GNU_SOURCE

    #include "commands_server.h"
    #include <sys/select.h>
    #include <arpa/inet.h>
    #include <sys/stat.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <limits.h>
    #include <stdbool.h>
    #include <uuid/uuid.h>
    #include "logging_server.h"
    #include "logging_client.h"

static const int CLIENT = 256;

typedef struct server_s server_t;

struct server_s {
    struct sockaddr_in s_adr;
    client_t client[256];
    user_t users[256];
    int user_count;
    fd_set read, write;
    int s_serv;
    int max_client;
    char *stock_path;
};

/******* FUNCTION SERVER *******/
int create_socket(int, server_t *);
int create_bind_listen(server_t *);
int create_accept(server_t *);
int create_select(server_t *);
int create_server(int, server_t *);


/******* FUNCTION PROTOTYPE *******/
int core(int, server_t *);
int handle_commands(client_t *);
int handle_client(client_t *);


/******* CHECKER && GETER && UTILS *******/
int is_number(char *, int);
int handle_error(const char *);
void help(void);
int counter(client_t *, char *, char);
char *remove_quote(char *);


#endif /* !SERVER_H_ */
