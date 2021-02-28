# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sserbin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/23 12:47:09 by sserbin           #+#    #+#              #
#    Updated: 2021/02/28 19:03:58 by sserbin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c utils.c verif.c service.c
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = gcc
NAME = libftprintf.a
RM = rm -f

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all:
	$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
