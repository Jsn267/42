NAME	=	ft_printf.a

INC	=	libft.h	\
		ft_printf.h

SRC	=	ft_printf_utils.c	\
		ft_utils_spt.c	\
		ft_printf.c	\
		ft_subft.c	\
		ft_sec_subft.c

OBJ	=	$(SRC:.c=.o)

LIBFT_OBJ	=	libft/*.o

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra

all:	$(NAME)

bonus:	$(NAME)

makelibft:
	$(MAKE) -C libft all bonus

cleanlibft:
	rm clean -C libft

%.o	:	%.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(NAME):	$(OBJ) makelibft
	ar rcs $@ $(OBJ) $(LIBFT_OBJ)

clean:
	rm -f $(OBJ) $(LIBFT_OBJ)
	$(cleanlibft)

fclean:	clean
	rm -f $(NAME) libft/libft.a

re:
	fclean all

.PHONY:	all clean fclean re
