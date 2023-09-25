#include "libft.h"

void    *ft_memmove(void *dst,const void *src,size_t len)
{
    unsigned char *dptr;
    const unsigned char *sptr;

    dptr = dst;
    sptr = src;

    while (*dptr)
    {
        dptr++;
    }
    while (len--)
    {
        if (*sptr != 0)
            *dptr++ = *sptr++;
        else
            *dptr++ = '0';//confuse
    }
    return (dst);
}
