# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 18:10:05 by abdel-ou          #+#    #+#              #
#    Updated: 2023/11/15 12:46:23 by haguezou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3D
NAME_B=cub3D_bonus
FRAEMWORKS = -L /usr/lib -lmlx -framework OpenGL -framework AppKit
FLAGS= -ffast-math -Wall -Wextra -Werror #-fsanitize=address -g

SRC=	./mandatory/main.c ./mandatory/drow_line.c \
		./mandatory/draw.c ./mandatory/key_hook.c  ./mandatory/horizontal_rays.c ./mandatory/vertical_ray.c \
		./mandatory/texture.c ./mandatory/draw_util.c\
		./mandatory/parsing/check_inside_maps.c \
	    ./mandatory/parsing/parse.c ./mandatory/parsing/new_parse.c \
		./mandatory/parsing/parse_params.c ./mandatory/parsing/utils_functions.c \
		./mandatory/parsing/utils_functions2.c ./mandatory/parsing/utils_functions3.c 

SRC_BONUS=		./bonus/main.c ./bonus/drow_line.c \
				./bonus/draw.c ./bonus/key_hook.c  ./bonus/horizontal_rays.c ./bonus/vertical_ray.c ./bonus/mini_map.c \
				./bonus/texture.c ./bonus/draw_util.c\
				./bonus/parsing/check_inside_maps.c \
	    		./bonus/parsing/parse.c ./bonus/parsing/new_parse.c \
				./bonus/parsing/parse_params.c ./bonus/parsing/utils_functions.c \
				./bonus/parsing/utils_functions2.c ./bonus/parsing/utils_functions3.c 

INCLUDES= -I /usr/include

OBJ = $(SRC:.c=.o)
OBJBONUS = $(SRC_BONUS:.c=.o)

LIBFT = ./libft/libft.a

GNL = ./gnl/get_next_line.c ./gnl/get_next_line_utils.c 

HEADER = ./mandatory/cub3d.h ./gnl/get_next_line.h

HEADER_BONUS = ./bonus/cub3d_bonus.h ./gnl/get_next_line.h

all	:$(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(MAKE) -C ./libft all
	$(CC) $(OBJ) $(GNL) $(LIBFT) $(FLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(NAME_B)
$(NAME_B): $(OBJBONUS) $(HEADER_BONUS)
	@$(MAKE) -C ./libft all
	$(CC) $(OBJBONUS) $(GNL) $(LIBFT) $(FLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)

%.o:%.c
	$(CC) $(FLAGS) -c $^ -o $@ 

fclean:
	@$(MAKE) -C ./libft fclean
	rm -rf $(NAME) $(OBJ) $(OBJBONUS) $(NAME_B)

clean:
	@$(MAKE) -C ./libft clean
	rm -rf $(OBJ) $(OBJBONUS)

re:fclean $(NAME)