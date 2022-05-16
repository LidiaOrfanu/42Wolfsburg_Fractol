# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 12:40:30 by lorfanu           #+#    #+#              #
#    Updated: 2022/05/12 13:00:43 by lorfanu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = src/main.c\
src/libft_utils.c\
src/utils.c\
src/keys_and_hooks_ops.c\
src/fractol.c\
src/complex_ops.c\

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): mlx_all $(OBJS)
	$(CC) -o $(NAME) $(OBJS) mlx/libmlx_Linux.a -L/usr/include/X11/extensions -lX11 -lXext -lm

mlx_all:
			cd mlx && ./configure

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all, clean, fclean, re
