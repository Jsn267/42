NAME    =   libftprintf.a

INC =   libft.h \
        ft_printf.h

SRCS    =   ft_printf_utils.c   \
        ft_utils_spt.c  \
        ft_printf.c \
        ft_subft.c  \
        ft_sec_subft.c

OBJS    = ${SRCS:.c=.o}

LIBFT_PATH      =   ./libft

LIBFT           =   $(LIBFT_PATH)/libft.a

CC      = cc

CFLAGS  = -Wall -Wextra -Werror

RM      = rm -f

all: $(NAME)

bonus: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) all bonus

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rc ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}
	make -C $(LIBFT_PATH) clean

fclean: clean
	${RM} ${NAME}
	${RM} libft.a
	make -C $(LIBFT_PATH) fclean

re: fclean all
.PHONY: all bonus clean fclean re