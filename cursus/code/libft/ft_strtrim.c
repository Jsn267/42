#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    char    *trimed;
    char    *start;
    char    *end;

    while (set)
    {
        start = ft_strchr(s1,set);
        end = ft_strrchr(s1,set);
        set++;
    }
    printf("Start :%s",start);
    printf("End :%s",end);

    return (trimed);
}
int main(void)
{
    char a[]="abthis is testing .ba";
    char b[]="ab";
    ft_strtrim(a,b);
}