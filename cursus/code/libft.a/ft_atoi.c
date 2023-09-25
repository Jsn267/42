#include "libft.h"

int	neg(int sign)
{
	if(sign % 2 == 1)
		return 1;
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 0;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32 )
			i++;
	while (str[i] == '+' || str[i] == '-')
	{
		sign++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if (neg(sign) == 1)
	{	
		num = -num;
	}
	return (num);
}
