/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** client
*/

#ifndef _CLIENT_H_
    #define _CLIENT_H_

    #include <sys/select.h>
    #include <arpa/inet.h>
    #include <sys/stat.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <limits.h>
    #include <uuid/uuid.h>
    #include <stdbool.h>
    #include "logging_server.h"
    #include "logging_client.h"

typedef struct client_s client_t;

struct client_s {
    struct sockaddr_in adr;
    fd_set read, write;
    int s_client;
    int port;
    char *ip;
    char *cmd;
    char cmd_c[1024];
    int index;
    uuid_t gener_uuid;
    char *uuid;
    char *username;
    bool is_logged;
};

/******* CLIENT *******/
int core_client(client_t *);
void create_socket_client(client_t *);
void create_connect(client_t *);
int create_select_client(client_t *);
int check_crlf(client_t *);


/******** COMMANDS ********/
int handle_login_client(client_t *);
int handle_logout_client(client_t *);
int handle_users_client(client_t *);
int handle_user_client(client_t *);
int handle_send_client(client_t *);
int handle_messages_client(client_t *);
int handle_commands(client_t *);
int display_connected(client_t *);

/******** UTILS ********/
void help(void);
int handle_error(const char *);

#endif /* !CLIENT_H_ */
