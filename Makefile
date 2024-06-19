# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/02 10:19:02 by fbelkaid          #+#    #+#              #
#    Updated: 2024/06/16 18:15:18 by fbelkaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIRS = ./src
INC_DIR = ./Includes
CFLAGS = -Wall -Wextra -Werror

SRCS_SERVER = $(SRCS_DIRS)/server.c $(SRCS_DIRS)/tools.c $(SRCS_DIRS)/linked_list.c

SRCS_CLIENT = $(SRCS_DIRS)/client.c $(SRCS_DIRS)/tools.c $(SRCS_DIRS)/linked_list.c

SRCS_BSERVER = $(SRCS_DIRS)/server_bonus.c $(SRCS_DIRS)/tools.c $(SRCS_DIRS)/linked_list.c

SRCS_BCLIENT = $(SRCS_DIRS)/client_bonus.c $(SRCS_DIRS)/tools.c $(SRCS_DIRS)/linked_list.c

NAME = server client

CC= cc
AR= rm -f
all: $(NAME) $(INC_DIR)

$(NAME): $(SRCS_SERVER) $(SRCS_CLIENT)
	 @$(CC) $(CFLAGS) $(SRCS_SERVER) -I $(INC_DIR)  -o server
	 @$(CC) $(CFLAGS) $(SRCS_CLIENT) -I $(INC_DIR) -o client


	
bonus : 
	@$(CC) $(CFLAGS) $(SRCS_BSERVER) -I $(INC_DIR)  -o server_bonus
	@$(CC) $(CFLAGS) $(SRCS_BCLIENT) -I $(INC_DIR)  -o client_bonus

clean:
	@$(AR) $(NAME) 

fclean: clean
	@$(AR) $(NAME) server_bonus client_bonus

re: fclean all
