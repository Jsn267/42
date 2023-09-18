#include "libft.h"

char    *ft_strdup(const char *s1)
{
    char    *cpy;
    int     len;

    if (ft_strlen(*s1) == 0)
        return (0);

    while(*s1)
        len++;

    cpy = malloc(len);
    ft_strlcpy(*cpy,*s1,len);
    return (cpy);
}