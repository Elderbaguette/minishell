SRCS			=	main.c\
					execute.c\
					init.c\
					pipex.c\
					here_doc.c\
					utils.c\
					b_main.c\
					b_builtins.c\
					b_unset_opti.c\
					b_utils.c\
					b_env.c\
					expound.c\
					utils_dos.c\
					split_coat.c\
					split_coat_utils.c\
					ft_free.c\
					signal.c\
					exec_utils.c\

SRCSBONUS		=	main_bonus.c\

OBJS			=	$(SRCS:.c=.o)

OBJSBONUS		=	${SRCSBONUS:.c=.o}

NAME			=	minishell
CC				=	cc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -g3

LIBRARIES		=	-L libftprintfgnl -lftprintfgnl -lreadline
INCLUDES		=	-Ilibftprintfgnl

all:			$(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror $(INCLUDES) -O3 -c $< -o $@

$(NAME):		$(OBJS)
				@make -C libftprintfgnl
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBRARIES)

bonus:			$(NAME_BONUS)

$(NAME_BONUS):	$(OBJSBONUS)
				@make -C libftprintfgnl
				@$(CC) $(CFLAGS) $(OBJSBONUS) -o $(NAME_BONUS) $(LIBRARIES)
clean:
				@make -C libftprintfgnl clean
				@$(RM) $(OBJS) $(OBJSBONUS)


fclean:			clean
				@make -C libftprintfgnl fclean
				@$(RM) $(NAME) $(NAME_BONUS)


re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
