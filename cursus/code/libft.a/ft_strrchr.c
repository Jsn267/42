#include "libft.h"

char    *ft_strrchr(const char* str,int i)
{
    const char*    pstr;
    int    target;
    
    pstr = str;
    target = i;

    while (*pstr)//chg to the last position
    {
        pstr++;
    }
    while (pstr != str && *pstr != target)//chg the pointer of pstr to the starter
    {
        pstr--;
    }
    if (target == *pstr)
        return ((char *)(pstr));
    return (0);

}

