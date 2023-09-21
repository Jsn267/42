#include "libft.h"

size_t      ft_strlcat(char *dst, const char *src, size_t dst_size)
{
    size_t  total;
    size_t  dst_len;
    size_t  src_len;

    dst_len = ft_strlen(dst);
    src_len = ft_strlen(src);
    total = dst_len + src_len;

    if( dst_size <= dst_len)
        return (src_len + dst_size);

    while (*src && (dst_len + 1) < dst_size)
    {
        dst[dst_len] = *src;
        dst_len++;
        src++;
    }
    dst[dst_len] = '\0';
    return (total);
}