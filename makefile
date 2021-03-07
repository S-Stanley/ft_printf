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

SRCS = ft_printf.c verif.c service.c printer.c utils/utils1.c utils/utils2.c utils/utils3.c utils/utils4.c utils/utils5.c utils/utils6.c utils/utils7.c printer/deal_with_c.c
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

re:	fclean $(NAME)