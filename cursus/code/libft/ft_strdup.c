#include "libft.h"

char    *ft_strdup(const char *s1)
{
    char    *cpy;
    int     len;

    len = 0;

    if (ft_strlen(s1) == 0)
        return (0);

    while(*s1)
        len++;

    cpy = malloc(len);
    ft_strlcpy(cpy,s1,len);
    return (cpy);
}
int     main(void)
{
    char a[]="Apple";
    printf("Substring result:: %s\n",ft_strdup(a));
}