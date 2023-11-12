# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 14:24:16 by haguezou          #+#    #+#              #
#    Updated: 2022/10/24 23:04:43 by haguezou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc 

CFLAGS = #-Wall -Wextra -Werror

SRC  = ft_isalnum.c ft_isdigit.c ft_memcpy.c ft_strlen.c ft_isalpha.c ft_memmove.c ft_bzero.c ft_isascii.c ft_isprint.c ft_memset.c ft_strlcpy.c \
		ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
		ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c

BONUS =  ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c ft_lstsize_bonus.c \
		 ft_lstlast_bonus.c 

OBJ = $(SRC:.c=.o)

BONUSOBJ =$(BONUS:.c=.o)

HEADER = libft.h

all : $(NAME)

%.o : %.c $(HEADER)
	$(CC) -c $< $(CFLAGS)

$(NAME): $(OBJ) 
	ar -rc $(NAME) $(OBJ)  

bonus:  $(BONUSOBJ)
	ar -rc $(NAME) $(BONUSOBJ)

clean : 
	rm -rf *.o


fclean : clean
	rm -rf $(NAME)

re: fclean all
