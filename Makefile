# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 08:54:59 by crebelo-          #+#    #+#              #
#    Updated: 2023/10/02 08:54:59 by crebelo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -g

SRC = main.c \
	  check_validations.c \
	  init_args.c \
	  moves_list_a.c \
	  moves_list_b.c \
	  moves_list_both.c \
	  sort_list.c \
	  small_sort.c \
	  big_sort.c \
	  utils_main_1.c \
	  utils_main_2.c \
	  utils_args_1.c \
	  utils_args_2.c \
	  utils_list.c \
	  utils_big_1.c \
	  utils_big_2.c \
	  utils_big_3.c

OBJ = $(SRC:.c=.o)

CC = cc

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
