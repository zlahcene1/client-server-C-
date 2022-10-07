##
## EPITECH PROJECT, 2022
## my_teams
## File description:
## Makefile
##

SRCS		=		$(wildcard src/core/*.c)					\
					$(wildcard src/client/*.c)					\
					$(wildcard src/commands_features/*.c)

OBJS		= 		$(SRCS:.c=.o)

NAME		=		myteams_cli

CPPFLAGS	=		-I ../include/include_client -I ../libs/myteams

LDFLAGS		=		-L ../libs/myteams -lmyteams -luuid

CC			=		gcc

RM			= 		rm -f

all: 				$(NAME)

$(NAME): 			$(OBJS)
					$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
					mv $(NAME) ../
					echo -e "\033[01m\033[32mCompilation ok => ${NAME}\033[00m"

clean:
					$(RM) $(OBJS)

debug:				CFLAGS += -g3 -W -Wall -Wextra
debug:				re

debug+:				CFLAGS += $(debug) -Wpedantic -Wno-long-lon -Werror
debug+:				re

fclean: 			clean
					$(RM) ../$(NAME)

re: 				clean fclean all

.PHONY: 			all clean fclean debug debug+ re
