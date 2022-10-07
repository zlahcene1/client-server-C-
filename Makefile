##
## EPITECH PROJECT, 2022
## my_teams
## File description:
## Makefile
##

CLIENT          =       client
SERVER     		=       server

all:                    $(CLIENT) $(SERVER)

client:
						@make -C $(CLIENT) -f Makefile -s

server:
						@make -C $(SERVER) -f Makefile -s

clean:
						@make clean -C $(CLIENT) -f Makefile -s
						@make clean -C $(SERVER) -f Makefile -s

fclean:
						@make fclean -C $(CLIENT) -f Makefile -s
						@make fclean -C $(SERVER) -f Makefile -s

debug:
						@make debug -C $(CLIENT) -f Makefile -s
						@make debug -C $(SERVER) -f Makefile -s

debug+:
						@make debug+ -C $(CLIENT) -f Makefile -s
						@make debug+ -C $(SERVER) -f Makefile -s

re:
						@make re -C $(CLIENT) -f Makefile -s
						@make re -C $(SERVER) -f Makefile -s

.PHONY:                 all client server clean fclean