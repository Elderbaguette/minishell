# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aproust <aproust@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 11:25:53 by aproust           #+#    #+#              #
#    Updated: 2023/09/26 14:40:28 by aproust          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c\
	ft_putchar_fd.c\
	ft_putnbr_fd.c\
	ft_putstr.c\
	ft_put_uint.c\
	ft_strlen.c\

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

all: ${NAME}

.c.o :
	 ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
${NAME}: $(OBJS)
			ar rcs ${NAME} ${OBJS}
clean:
			${RM} ${OBJS}

fclean: clean
			${RM} ${OBJS} ${NAME}

re: fclean all

.PHONY:		all clean fclean re
