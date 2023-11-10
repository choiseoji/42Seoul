# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 21:30:55 by seojchoi          #+#    #+#              #
#    Updated: 2023/03/23 16:49:44 by seojchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_putchar.c ft_putnbr_hex.c ft_putnbr_u.c ft_putnbr.c ft_putp.c ft_putstr.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
HEADER = ft_printf.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $^ 

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all