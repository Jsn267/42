#include "libft.h"

char    *strnstr(const char *haystack, const char *needle, size_t len)
{
        int     i;
        int     j;
        char    *hay;

        i = 0;
        hay = (char *)haystack;
        
        if (ft_strlen(needle) == 0 || haystack == needle)
                return (hay);
        while (hay[i] != '\0' && i < len)
        {
            j = 0;
            while (hay[i + j] != '\0' && needle[j] != '\0' && hay[i + j] == needle[j] && i + j < len)//check the needle
            {
                j++;
            }
            if (j == ft_strlen(needle))
                return (hay + i);
            
            i++;
        }
        return (0);
}