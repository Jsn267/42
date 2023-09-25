NAME	=	libft.a # name of the library to be created

#list all the source files
SRC_MAND	=	ft_isalpha.c	\
			ft_isdigit.c	\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_strlen.c	\
			ft_memset.c	\
			ft_bzero.c	\
			ft_memcpy.c	\
			ft_memmove.c	\
			ft_strlcpy.c	\
			ft_strlcat.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_strchr.c	\
			ft_strrchr.c	\
			ft_strncmp.c	\
			ft_memchr.c	\
			ft_memcmp.c	\
			ft_strnstr.c	\
			ft_atoi.c	\
			ft_calloc.c	\
			ft_strdup.c	\
			ft_substr.c	\
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c	
			

OBJ_MAND	= $(SRC_MAND:.c=.o) # pattern substitution

CC			= gcc

CFLAGS		+= -Wall -Werror -Wextra -g # g: for debugging

LFLAGS		+= -I. # to indicate to the linker where to find header files 

RM			= rm -rf

AR			= ar rcs # ar:create an archive file  ||r:replace or add  ||c:create if doesn't exit ||s:write into archive file

RANLIB		= ranlib # generate an index for an archive file

all				:			$(NAME)
							@echo Compiling library "libft.a" File "Only Mandatory Parts": $@ ...
# @echo: to print the msg  || $@ that indicate all

$(NAME)			:			$(OBJ_MAND)
							@echo Compiling Library File: $@ ...
							$(AR) $(NAME) $(OBJ_MAND)
							$(RANLIB) $(NAME)

%.o				:			%.c
							@echo Compiling Binary Files: $@ ...
							$(CC) $(CFLAGS) -c $< -o $@ $(LFLAGS)
# %.o is target pattern 
# %.c is prerequest pattern
# $< indicate first prerequest

clean			:	
							@echo Cleaning The .o Generated Files: $@ ...
							$(RM) $(OBJ_MAND) 


fclean			:			clean
							@echo Cleaning All ".o & libft.a" Generated Files:
							$(RM) $(NAME)

re				:			fclean all
							@echo Cleaning All ".o & libft.a" Generated Files And Remake Everything:


.PHONY			:			all clean fclean re 