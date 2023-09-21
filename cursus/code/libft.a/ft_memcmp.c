#include "libft.h"
int    ft_memcmp(const void *dst, const void *src, size_t n)
{
    const char    *ptr1;
    const char    *ptr2;

    ptr1 = dst;
    ptr2 = src;

    while (n--)
    {
        if(*ptr1 != *ptr2)
            return (*ptr1 - *ptr2);
    ptr1++;
    ptr2++;
    }
    return (0);
}
int    main(void)
{
    char a[] = "abCde";
    char b[] = "abcde";
    printf("result :: %d\n",ft_memcmp(a,b,5));
}
