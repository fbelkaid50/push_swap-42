# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 03:37:28 by fbelkaid          #+#    #+#              #
#    Updated: 2024/05/17 16:09:02 by fbelkaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

SRC = ./libft/ft_atoi.c ./libft/ft_split.c ./libft/linked_list.c \
	five.c main.c moves1.c moves2.c push_swap.c three.c one_hundred.c five_hundred.c \

SRC_BONUS = checker.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
	./libft/linked_list.c ./libft/ft_atoi.c main_checker.c ./libft/ft_split.c moves1.c moves2.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


clean :
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all