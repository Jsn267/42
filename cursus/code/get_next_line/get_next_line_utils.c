#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	char	*tmp;
	size_t	len;

	len = 0;
	tmp = (char *)s;
	while (*tmp++)
		len++;
	return (len);
}
char	*ft_strchr(const char *str, int character)
{
	const char	*ptr;
	int			target;

	ptr = str;
	target = character;
	while (*ptr != '\0' && *ptr != target)
	{
		ptr++;
	}
	if (*ptr == target)
		return ((char *)ptr);
	return (0);
}
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dptr;
	unsigned char	*sptr;
	size_t			i;

	if (!dest && !src)
		return (0);
	dptr = (unsigned char *)dest;
	sptr = (unsigned char *)src;
	i = 0;
	while (i++ < n)
		*dptr++ = *sptr++;
	return (dest);
}
char	*ft_strdup(const char *s1)
{
	char	*rtn;
	size_t	len;

	len = ft_strlen(s1) + 1;
	rtn = (char *)malloc(sizeof(char) * len);
	if (!rtn)
		return (NULL);
	rtn = ft_memcpy(rtn, s1, len);
	return (rtn);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	char	*save;

	len = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1 && s2)
		len = ft_strlen(s2) + 1;
	else if (s1 && s2)
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(*str) * (len));
	if (!(str))
		return (NULL);
	save = str;
	if (s1)
		while (*s1)
			*str++ = *s1++;
	if (s2)
		while (*s2)
			*str++ = *s2++;
	*str = 0;
	return (save);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtn;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	rtn = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!rtn)
		return (NULL);
	while (i < len)
	{
		rtn[i] = *(s + start + i);
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
