#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int,char*))//(*f):function pointer
{
    size_t i;

    i = 0;

    while (s[i])
    {
        f(i,s[i]);
        i++;
    }
}
