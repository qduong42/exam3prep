NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Werror -Wextra
SRCS= ft_printf.c
OBJS=${SRCS:.c=.o}
RM = rm -rf

all: $(NAME)

$(NAME) : ${OBJS}
	ar rcs $(NAME) ${OBJS}

clean:
	${RM} ${OBJS} $(BONUS_OBJS)
	${RM} */*.o

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY:	all clean fclean re
