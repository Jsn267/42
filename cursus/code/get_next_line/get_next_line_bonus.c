#include "get_next_line_bonus.h"

char	*renew_line(char *saved)
{
	char	*rtn;
	int		i;

	if (!saved)
		return (NULL);
	i = ft_gnl_strchr(saved) + 1;
	if (i == 0 || saved[i] == '\0')
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}
	rtn = ft_gnl_strdup((saved + i));
	if (!rtn)
		return (NULL);
	free(saved);
	saved = NULL;
	return (rtn);
}

char	*ft_get_line(char *saved)
{
	int		len;
	int		i;
	char	*rtn;

	i = -1;
	if (!saved || saved[0] == '\0')
		return (NULL);
	len = ft_gnl_strchr(saved) + 1;
	if (len == 0)
		len = ft_gnl_strlen(saved);
	rtn = (char *)malloc(sizeof(char) * (len + 1));
	if (!rtn)
		return (NULL);
	while (++i < len)
		rtn[i] = saved[i];
	rtn[i] = '\0';
	return (rtn);
}

char	*add_data(int fd, char *saved)
{
	int		byte_read;
	char	*buf;

	buf = (char *)malloc((sizeof(char)) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	byte_read = 1;
	while (byte_read != 0 && ft_gnl_strchr(saved) == -1)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(saved);
			free(buf);
			saved = NULL;
			buf = NULL; // added
			return (NULL);
		}
		buf[byte_read] = '\0';
		saved = ft_gnl_strjoin(saved, buf);
	}
	free(buf);
	return (saved);
}

char	*get_next_line(int fd)
{
	char *next_line;
	static char *saved[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	saved[fd] = add_data(fd, saved[fd]);
	if (!saved[fd])
		return (NULL);
	next_line = ft_get_line(saved[fd]);
	saved[fd] = renew_line(saved[fd]);
	return (next_line);
}