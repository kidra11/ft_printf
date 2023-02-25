# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsion <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 21:16:46 by nsion             #+#    #+#              #
#    Updated: 2023/02/24 18:04:34 by nsion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_find.c

NAME	= libftprintf.a

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

OBJS	= $(SRCS:.c=.o)

all	: $(NAME)

.c.o	:
	$(CC) -I. -o $@ -c $? $(CFLAGS)

$(NAME)	: $(OBJS)
	ar cr $(NAME) $?

clean	:
	$(RM) $(OBJS) 

fclean	:	clean
	$(RM) $(NAME)

re	: fclean all
