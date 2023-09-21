#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    char    *arr;
    char    chr;

    arr = (char *)s;
    chr = (char)c;

    while (n--)
    {
        if (*arr == chr)
            return (arr);
        arr++;    
    }
    return (0);
}