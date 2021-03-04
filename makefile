# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sserbin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/23 12:47:09 by sserbin           #+#    #+#              #
#    Updated: 2021/02/28 19:43:00 by sserbin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c utils.c verif.c service.c printer.c
OBJS = $(SRCS:.c=.o)
FLAGS = 
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
