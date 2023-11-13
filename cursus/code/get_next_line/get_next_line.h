#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

size_t	        ft_strlen(const char *s);
char	        *ft_strchr(const char *str, int character);
void	        *ft_memcpy(void *dest, const void *src, size_t n);
char    	    *ft_strdup(const char *s1);
char	        *ft_strjoin(char const *s1, char const *s2);
char	        *ft_substr(char const *s, unsigned int start, size_t len);
char            *get_next_line(int fd);

#endif