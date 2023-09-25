#include "libft.h"
#include <libc.h>
char    *ft_strchr(const char *str,int character)
{
    const char   *ptr;
    int    target;

    ptr = str;
    target = character;

    while (*ptr != '\0' && *ptr != target )
    {
        ptr++;
    }
    if (*ptr == target)
        return ((char *)ptr);
    return (0);
}
/*
int     main(void)
{
    char a[] = "abcde";
    int t = 'c';
    char *result = ft_strchr(a,t);
    printf("sys ::%s\n",strchr(a,t));
    printf("my ;;%s", result);
}
*/