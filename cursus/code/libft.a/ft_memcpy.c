#include "libft.h"

void    *ft_memcpy(void *dest,const void *src,size_t n)
{
    unsigned char *dptr;
    const unsigned char *sptr;

    dptr = dest;
    sptr = src;

    if (!dest && !src)
        return (NULL);

    while (n--)
    {
        *dptr++ = *sptr++;
    }
    return ((void *)dest);
}

