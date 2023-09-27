#include "libft.h"

size_t ft_intlen(int n)
{
        size_t l;
        l = 1;
        while (n > 10)
        {
            n /= 10;
            l++;
        }
        return (l);
}
char *ft_strrev(char *str)
{
    size_t	i;
	size_t	len;
	char	tmp;

	if (!str || !*str)
		return (str);
	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
		i++;
	}
	return (str);
}
char *ft_itoa(int n)
{
    int r;
    int d;//divider
    size_t i;
    size_t len;
    char sign;
    char *rtn;

    sign = 0;
    i = 0;
    d = 1;

    /*if (n < -2,147,483,648 || n > 2,147,483,647)//out of range
    {
        return (ft_strdup("-2147483648"));
    }*/

    if (n < 0)
    {
        sign = '-';
        n = n * -1;
    }

    len = ft_intlen(n);

    if (!(rtn = ft_calloc((len+1),sizeof(char))))//1 for null terminated and return null if the int is emty
    {
        return (0);
    }
    while (i < len)
    {
        r = n % 10;
        n = n / 10;
        rtn[i] = r + 48;
        i++;
    }
    if (sign == '-')
        rtn[i] = '-';
    
    return (ft_strrev(rtn));

}
/*int main(void)
{
    int a = 2345;
    char *b = ft_itoa(a);
    
    printf("char value:: %s",b);
}*/