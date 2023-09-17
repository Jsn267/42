#include<unistd.h>

int	main(int argc,char* argv[])
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while(i < argc)
	{
		j = 0;
		while(argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
	return (1);
}
