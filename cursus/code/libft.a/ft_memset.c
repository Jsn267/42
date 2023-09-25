#include "libft.h"
void    *ft_memset(void *s,int c,size_t n)
{
    unsigned char *ptr;
    ptr = s;
    while(n--)
    {
        *ptr++ = c;
    }
    s = ptr;
    return (s);
}
