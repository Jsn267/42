#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char   *substr;
    size_t     count;

    count = 0;
    substr = (char *)malloc((len + 1) * (sizeof(char)));

    if (ft_strlen(s) < len || (unsigned int)ft_strlen(s) < start)// for allocation fails
        return (0);

    while(count < len)
    {
        substr[count] = s[count + start];
        count++;
    }        
    return (substr);
}
int     main(void)
{
    char a[]="Apple";
    printf("Substring result:: %s\n",ft_substr(a,3,5));
}