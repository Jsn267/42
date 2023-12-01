#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

int ft_gnl_strlen(char *str);
int	ft_gnl_strchr(const char *str);
char    *ft_gnl_strjoin(char *str1,char *str2);
char	*ft_gnl_strdup(char *s);

char	*get_next_line(int fd);
char	*add_data(int fd,char *saved);
char	*ft_get_line(char *saved);
char	*renew_line(char *saved);

#endif