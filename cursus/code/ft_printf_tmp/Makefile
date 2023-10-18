NAME = libftprintf.a

SRC	=	ft_printf.c \
		ft_print_on_screen.c \
		ft_args_init.c \
		ft_printf_utils.c \
	 	ft_hex_utils.c 

OBJ	=	$(SRC:.c = .o)

LIBFT_DIR	=	/42/cursus/code/libft.a
LIBFT_SRC	=	$(wildcard $(LIBFT_DIR)/*.c)
LIBFT_OBJ	=	$(LIBFT_SRC:.c=.o)

CC = gcc

FLG = -Wall -Werror -Wextra

%.o	: %.c
	@$(CC) $(FLG) -c -o $@ $^

$(NAME)	:	$(OBJ) $(LIBFT_OBJ)
			@ar rcs $(NAME) $(OBJ) $(LIBFT_OBJ)
			@ranlib $(NAME)

all	:	$(NAME)

clean:
	@/bin/rm -f $(OBJ) $(LIBFT_OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	rm -f $(NAME) libft.a/libft.a

re: fclean all

