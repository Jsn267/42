#include "libft.h"

size_t  ft_strlen(const char *s)
{
    char    *tmp;
    size_t  len;

    len = 0;
    tmp = (char *)s;
    
    while(*tmp++)
        len++;
        

    return (len);
}