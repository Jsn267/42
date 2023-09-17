#include<unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int	res;

	res = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		while(power != 1)
		{
			res *= nb;
			power--;
		}
}
