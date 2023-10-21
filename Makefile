# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 18:10:05 by abdel-ou          #+#    #+#              #
#    Updated: 2023/10/21 12:32:05 by abdel-ou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3d
FRAEMWORKS=-L /usr/lib -lmlx -framework OpenGL -framework AppKit
FLAGS=  

SRC=	main.c drow_line.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		 load_map.c draw.c key_hook.c grid_drow.c horizontal_rays.c vertical_ray.c mini_map.c \
		 texture.c \


INCLUDES=-I /usr/include

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all	:$(NAME)

%.o:%.c
	$(CC) $(FLAGS) -c $^ -o $@ 

fclean:
	rm -rf $(NAME) $(OBJ) $(OBJBONUS)

clean:
	rm -rf $(OBJ)

re:fclean $(NAME)