#include "libft.h"

char    *ft_strdup(const char *s1)
{
    char    *cpy;
    char    *tmp;
    int     len;
    
    tmp = (char *)s1;//for ptr location
    len = 1;//for null terminated

    if (ft_strlen(s1) == 0)
        return (0);

    while(*tmp++)
        len++;

    cpy = malloc(len);
    ft_strlcpy(cpy,s1,len);
    return (cpy);
}
