NAME = libftprintf.a

SRC	=	ft_printf.c \
		ft_print_on_screen.c \
		ft_args_init.c \
		ft_print_char.c \
		ft_print_s tr.c \
	 	ft_print_ptr.c \
	 	ft_print_int.c \
	 	ft_allintlen.c \
	 	ft_puthex_fd.c \
	 	ft_print_all_nbr.c

OBJ	= $(SRC:.c = .o)

LIBFT_OBJ = libft.a/*.o

CC = gcc

FLG = -Wall -Werror -Wextra

%.o	: %.c
	@$(CC) $(FLG) -c -o $@ $^

$(NAME)	:	$(OBJ)
			@ar rc $(NAME) $(OBJ) $(LIBFT_OBJ)
			@ranlib $(NAME)

all	:	$(NAME)

clean:
	@/bin/rm -f $(OBJ) $(LIBFT_OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	rm -f $(NAME) libft/libft.a

re: fclean all

