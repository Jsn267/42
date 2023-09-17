#include<unistd.h>

int	main(int argc, char* argv[])
{
	int	i;
	int	j;
	int	z;
	char**	tmp;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (argv[i] < argv[j])
			{
				tmp = &argv[i];
				&argv[i] = &argv[j];
				&argv[j] = tmp;
			}
		j++;
		}
		z = 0;
		while (argv[i][z] != '\0')
		{
			write(1, &argv[i][z], 1);
			z++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (1);
}
