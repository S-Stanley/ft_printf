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

SRCS = ft_printf.c verif/verif.c services/service.c printer/printer.c utils/utilsa.c utils/utilsb.c utils/utilsc.c utils/utilsd.c utils/utilse.c utils/utilsf.c utils/utilsg.c utils/utilsh.c utils/utilsi.c utils/utilsj.c printer/printerb.c printer/printerc.c services/serviceb.c services/servicec.c
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

re:	fclean $(NAME)