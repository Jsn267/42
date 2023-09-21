#include "libft.h"

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
        while(n--)
        {
            if (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
            {
                s1++;
                s2++;
            }else
            return (*s1 - *s2);
        }
        return (0);
}