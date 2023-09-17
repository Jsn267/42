#include<unistd.h>

int	ft_find_next_prime(int nb)
{
        int     i;
        int     count;

        i = 1;
        count = 0;
        while (i <= nb)
        {
        if(nb % i == 0)
                count++;
        i++;
        }
        if (count == 2)
                return (nb);
        else
                return (ft_find_next_prime(nb+1));
}
