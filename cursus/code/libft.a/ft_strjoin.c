#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *result;
    int     len1;
    int     len2;

    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);

    result =(char *)malloc(sizeof(char) * (len1 + len2));
    ft_memmove(result,s1,len1);
    ft_memmove(result,s2,len2);
    return(result);
}
