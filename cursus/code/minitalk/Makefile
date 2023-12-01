NAME	=	minitalk.a

INC	=	libft.h	\
		ft_printf.h \
		minitalk.h

SRC	=	client.c	\
		server.c

OBJ	=	$(SRC:.c=.o)

FT_PRINTF_OBJ	=	ft_printf/*.o

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra

all:	$(NAME)

bonus:	$(NAME)

makeprintf:
	$(MAKE) -C ft_printf all bonus

cleanprintf:
	rm clean -C libft ft_printf

%.o	:	%.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(NAME):	$(OBJ) makeprintf
	ar rcs $@ $(OBJ) $(FT_PRINTF_OBJ)

clean:
	rm -f $(OBJ) $(FT_PRINTF_OBJ) ft_printf/libft/*.o
	$(cleanprintf)

fclean:	clean
	rm -f $(NAME) ft_printf/libft/libft.a ft_printf/ft_printf.a

re:
	fclean all

.PHONY:	all clean fclean re
