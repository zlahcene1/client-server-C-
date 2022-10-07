/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_

    #include <stdbool.h>
    #include <uuid/uuid.h>

struct server_s;
typedef struct user_s user_t;
typedef struct server_s server_t;
typedef struct client_s client_t;

struct user_s {
    char *username;
    uuid_t uuid;
    bool is_logged;
};

struct client_s {
    int fd;
    char cmd[1024];
    int index;
    user_t *user;
    server_t *server;
};

/******** FEATURES ********/
int handle_help(client_t *);

int handle_login(client_t *);
int handle_logout(client_t *);
int handle_users(client_t *);
int handle_user(client_t *);
int handle_send(client_t *);
int handle_messages(client_t *);
int handle_subscribe(client_t *);
int handle_subscribed(client_t *);
int handle_unsubscribe(client_t *);
int handle_use(client_t *);


/******** CREATE ********/
int handle_create(client_t *);

/******** LIST ********/
int handle_list(client_t *);

/******** INFO ********/
int handle_info(client_t *);


#endif /* !CLIENT_H_ */