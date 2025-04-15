# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/05 18:24:08 by lpalomin          #+#    #+#              #
#    Updated: 2025/04/15 12:56:12 by lpalomin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = 	so_long.c \
	map_validations.c \
	object_validations.c \
	map_methods.c \
	route_validation.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

MLX_DIR = /sgoinfre/shared/MLX42
MLX_INC = -I$(MLX_DIR)/include
MLX_LIB = -L$(MLX_DIR)/build -lmlx42 -lglfw -ldl -lm -lX11 -pthread

CFLAGS += $(MLX_INC)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft/

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft/ clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft/ fclean

re: fclean all

.PHONY: all bonus clean fclean re
