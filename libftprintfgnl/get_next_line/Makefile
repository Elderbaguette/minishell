# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aproust <aproust@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 11:25:53 by pdosso-d          #+#    #+#              #
#    Updated: 2023/09/26 14:40:23 by aproust          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	get_next_line.c\
		get_next_line_utils.c\

OBJS = ${SRCS:.c=.o}

NAME = libget_next_line.a
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
