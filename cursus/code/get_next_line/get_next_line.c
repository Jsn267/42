#include "get_next_line.h"

char	*extract(char **temp)
{
	char	*line;
	char	*ptr;

	ptr = *temp;
	while (*ptr && *ptr != '\n')
		++ptr;
	// ptr += (*ptr == '\n');
	if (*ptr == '\n')
		ptr = ptr + 1;
	line = ft_substr(*temp, 0, (size_t)(ptr - *temp));
	if (!line)
	{
		free(*temp);
		return (NULL);
	}
	ptr = ft_substr(ptr, 0, ft_strlen(ptr));
	free(*temp);
	*temp = ptr;
	return (line);
}
char	*ft_read(int fd, char *buf, char *backup)
{
	ssize_t	byte_read;
	char	*tmp;

	byte_read = 1;
	while (byte_read != '\0')
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(buf);
			free(backup);
			return (NULL);
		}
		else if (byte_read == 0)
		{
			break ;
		}
		buf[byte_read] = '\0';
		tmp = backup;
		backup = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (!backup)
		{
			free(buf);
			return (NULL);
		}
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (backup);
}
char	*get_next_line(int fd)
{
	char *buf;
	static char *tmp[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!tmp[fd])
		tmp[fd] = ft_strdup("");
	if (!tmp[fd])
		return (NULL);
	buf = (char *)malloc((sizeof(char) * (BUFFER_SIZE + 1)));
	if (!buf)
	{
		free(tmp[fd]);
		free(buf);
		return (NULL);
	}
	tmp[fd] = ft_read(fd, buf, tmp[fd]);
	if (!tmp[fd])
		return (NULL);
	if (!*tmp[fd])
	{
		free(tmp[fd]);
		tmp[fd] = NULL;
		return (NULL);
	}
	return (extract(&tmp[fd]));
}