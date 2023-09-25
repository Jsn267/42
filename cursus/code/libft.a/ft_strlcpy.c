#include "libft.h"
#include <libc.h>
size_t  ft_strlcpy(char *dst,const char *src,size_t maxlen)
{
 size_t   src_len;


 src_len = ft_strlen(src);

if ((src_len + 1) < maxlen)
{
    ft_memcpy(dst,src,(src_len + 1));
    dst[src_len + 1] = '\0';

}else if (maxlen != 0)
{
    ft_memcpy(dst,src,(maxlen - 1));
    dst[maxlen - 1] = '\0';
}
    return (src_len);
}

/*int main(void)
{
    char a[]= "abc";
    char b[]= "def";
    char c[]= "abc";
    char d[]= "def";
    ft_strlcpy(a,b,3);
    strlcpy(c,d,3);
    printf("MY :: %s\n",a);
    printf("SY :: %s\n",c);

}*/