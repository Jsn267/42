#include "get_next_line.h"

int	main(void)
{
	int fd;
	char *c;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
		perror("Error");
	c = get_next_line(fd);
	printf("the ans is ::%s", c);
}