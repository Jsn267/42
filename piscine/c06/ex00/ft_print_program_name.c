#include<unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	i = 0;
	while (argv[argc][i] != '\0')
	{
		write(1, &argv[argc][i], 1);
		i++;
	}
	return (0);
}
 
