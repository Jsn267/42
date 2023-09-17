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

int    main(void)
{
    char a[] = "01234";
    char b[] = "56789";

    ft_memcpy(a,b,3);
    
    printf("%s",a);
}
