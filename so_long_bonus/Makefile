# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 16:38:43 by njeanbou          #+#    #+#              #
#    Updated: 2023/12/20 19:02:37 by njeanbou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = 	so_long.c utils/utils.c utils/test_map.c utils/test_map_utils.c utils/split.c utils/render.c \
		utils/movement.c utils/mov_dir.c utils/mov_dir_test.c utils/chemin.c \
		utils/play_utils.c utils/init_img.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(src) $(OBJ) so_long.h
	$(CC) $(FLAGS) libmlx.dylib -framework OpenGL -framework AppKit $(SRC) -o $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) -Imlx $< -o $@

execute:
	./$(NAME) map/map2.ber

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
