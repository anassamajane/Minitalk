SERVER_SRC = server.c
CLIENT_SRC = client.c

OBJS_SERV = $(SERVER_SRC:.c=.o)
OBJS_CLIENT = $(CLIENT_SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME_S = server
NAME_C = client

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(OBJS_SERV)
	$(CC) $(CFLAGS) $(OBJS_SERV) -o $(NAME_S)

$(NAME_C): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_C)

clean:
	rm -f $(OBJS_SERV) $(OBJS_CLIENT)

fclean: clean
	rm -f $(NAME_S) $(NAME_C)

re: fclean all

.SECONDARY: $(OBJS_SERV) $(OBJS_CLIENT)

.PHONY: all clean fclean re
