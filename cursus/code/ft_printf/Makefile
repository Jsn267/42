NAME	=	libftprintf.a

SRC	=	ft_printf.c	\
		ft_printf_utils.c	\
		ft_subft.c

LIBFT_SRC = $(wildcard /Users/jason/Developer/42/cursus/code/libft.a/*.c)

OBJ	=	$(SRC:.c=.o)
LIBFT_OBJ	=	$(LIBFT_SRC:.c=.o)

CC	=	gcc

CFLAG	=	-Wall -Werror -Wextra

INC	=	libftprintf.h

%.o	:	%.c
		@$(CC) $(CFLAG) -c -o $@ $^

$(NAME)	:	$(OBJ) 
			@ar rcs $(NAME) $(OBJ) 
			@ranlib $(NAME)

bonus:	$(NAME)

all	:	$(NAME)

clean	:
			@/bin/rm -f $(OBJ) $(LIBFT_OBJ)

fclean	:	clean
			@/bin/rm -f $(NAME)

re	:	fclean all 