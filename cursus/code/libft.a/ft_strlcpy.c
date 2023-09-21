#include "libft.h"

size_t  ft_strlcpy(char *dst,const char *src,size_t maxlen)
{
 size_t   src_len;

 src_len = ft_strlen(src);

if ((src_len + 1) < maxlen)
{
    ft_memcmp(dst,src,(src_len + 1));
    dst[src_len + 1] = '\0';

}else if (maxlen != 0)
{
    ft_memcmp(dst,src,(maxlen - 1));
    dst[maxlen - 1] = '\0';
}
    return (src_len);

}