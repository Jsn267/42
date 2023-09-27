#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *rtn;
    size_t i;

    i = 0;
    rtn = ft_strdup(s);

    if(!s || !f)
    {
        return (0);
    }
    while (rtn[i])
    {
        rtn[i] = f(i,rtn[i]);
        i++;
    }
    return (rtn);

}
/*int main(void)
{
    char a[] ="abc";
    printf("resutl:: %s\n",ft_strmapi(a,ft_toupper));
}*/