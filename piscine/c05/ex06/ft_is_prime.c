#include<unistd.h>

int	ft_is_prime(int nb)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i <= nb)
	{
	if(nb % i == 0)
		count++;
	i++;
	}
	if (count == 2)
		return (1);
	else
		return (0);
}
