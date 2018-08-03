# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yacinesibous <yacinesibous@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/02 20:29:48 by yacinesibou       #+#    #+#              #
#    Updated: 2018/08/02 20:36:06 by yacinesibou      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME = client
SERVER_NAME = server

CC = gcc
CFLAGS = -Wall -Wextra -Werror -o

FILES_CLIENT = client.c

FILES_SERVER = server.c

SRC_CLIENT = $(addprefix src/client/, $(FILES_CLIENT))
SRC_SERVER = $(addprefix src/server/, $(FILES_SERVER))

all: $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

clean:
		rm -rf build

fclean: clean
		rm -rf $(NAME)

LIBFT = includes/libft/libft.a

mlibft.a: 
		make -C includes -C libft

client: $(CLIENT_NAME)

server: $(SERVER_NAME)

$(CLIENT_NAME): mlibft.a
		$(CC) $(CFLAGS) $(CLIENT_NAME) $(SRC_CLIENT) $(LIBFT)

$(SERVER_NAME): mlibft.a		
		$(CC) $(CFLAGS) $(SERVER_NAME) $(SRC_SERVER) $(LIBFT)