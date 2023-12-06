# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 16:38:43 by njeanbou          #+#    #+#              #
#    Updated: 2023/12/05 16:42:25 by njeanbou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(src) $(OBJ) so_long.h
	$(CC) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) -Imlx $< -o $@

execute:
	./$(NAME) maps/map.ber

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
