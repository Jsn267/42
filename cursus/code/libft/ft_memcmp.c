#include "libft.h"
int    ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const char    *ptr1;
    const char    *ptr2;

    ptr1 = s1;
    ptr2 = s2;

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
