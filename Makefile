# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhigelin <dhigelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 17:58:04 by dhigelin          #+#    #+#              #
#    Updated: 2017/11/28 11:47:24 by dhigelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft
LIB = -lft

NAME = fillit

SRCS = main.c \
	parse.c \
	ft_bitwise.c \
	recursive.c \
	ft_lstc.c \
	ft_putlnbr.c \
	ft_result.c \
	bits_operations.c \
	bits_conversion.c \
	define_height_width.c \

HEADER = fillit.h

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -Wall -Wextra -Werror -I $(LIBFT) -L $(LIBFT) $(LIB) -o $(NAME) *.c

clean:
	make clean -C libft/
	/bin/rm -f $(OBJS)

fclean: clean
	make fclean -C libft/
	/bin/rm -f $(NAME)

re:
	make fclean -C libft/
	make -C libft/
	make fclean all
