# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 18:10:05 by abdel-ou          #+#    #+#              #
#    Updated: 2023/11/14 17:59:41 by haguezou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3D
FRAEMWORKS = -L /usr/lib -lmlx -framework OpenGL -framework AppKit
FLAGS= -ffast-math -Wall -Wextra -Werror #-fsanitize=address -g

SRC=	main.c drow_line.c \
		draw.c key_hook.c  horizontal_rays.c vertical_ray.c mini_map.c \
		texture.c draw_util.c\
		./parsing/check_inside_maps.c \
	    ./parsing/parse.c ./parsing/new_parse.c \
		./parsing/parse_params.c ./parsing/utils_functions.c \
		./parsing/utils_functions2.c ./parsing/utils_functions3.c 

INCLUDES= -I /usr/include

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

GNL = ./gnl/get_next_line.c ./gnl/get_next_line_utils.c 

HEADER = cub3d.h ./gnl/get_next_line.h
all	:$(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(MAKE) -C ./libft all
	$(CC) $(OBJ) $(GNL) $(LIBFT) $(FLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -c $^ -o $@ 

fclean:
	rm -rf $(NAME) $(OBJ) $(OBJBONUS)

clean:
	rm -rf $(OBJ)

re:fclean $(NAME)