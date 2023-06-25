CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS_CLIENT = client.c utils.c
SRCS_SERVER = server.c utils.c
SRCS_CLIENT_BONUS = client_bonus.c utils.c
SRCS_SERVER_BONUS = server_bonus.c utils.c

OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
OBJS_SERVER = ${SRCS_SERVER:.c=.o}
OBJS_CLIENT_BONUS = ${SRCS_CLIENT_BONUS:.c=.o}
OBJS_SERVER_BONUS = ${SRCS_SERVER_BONUS:.c=.o}

all: $(CLIENT) $(SERVER) 
$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $^ -o $@

$(SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT_BONUS): $(OBJS_CLIENT_BONUS)
	$(CC) $(CFLAGS) $^ -o $@

$(SERVER_BONUS): $(OBJS_SERVER_BONUS)
	$(CC) $(CFLAGS) $^ -o $@
bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

clean:
	rm -rf $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)

fclean: clean
	rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

