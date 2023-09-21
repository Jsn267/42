#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *result;
    int     len1;
    int     len2;
    
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);

    result = (char *)ft_calloc( (len1 + len2 ), sizeof(char));

    if (!result)
        return (0);

    ft_memmove(result, s1, len1);
    ft_memmove(result + len1, s2, len2);
    result[len1 + len2 + 1] = '\0';
    
    return (result);
}