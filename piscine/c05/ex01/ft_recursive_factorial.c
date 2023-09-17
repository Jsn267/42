#include<unistd.h>

int	ft_recursive_factorial(int nb)
{
	int	res;

	res = 1;
	if (nb > 0)
	{
		res = nb * ft_recursive_factorial(nb - 1);
		return (res);
	}
	return (1);
}
