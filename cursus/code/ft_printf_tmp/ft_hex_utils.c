#include "libftprintf.h"

int ft_allintlen(long long num,int base)
{
    if (num < 0)
    {
        num = num * -1;
        return (1 + ft_allintlen(num / base,base));
    }
    if ((num/base) == 0)
    {
        return (1);
    }
    return (1 + ft_allintlen(num / base,base));//recheck 
}

void ft_puthex_fd(long long num,int fd)
{
    char *hex;

    hex = "0123456789abcdef";
    if (num / 16)
        ft_puthex_fd(num /16,fd);
    ft_putchar_fd(hex[num % 16],fd);
}

void ft_print_all_nbr(t_args *args,long long num ,int base, int fd)
{
    int sign;
    char *digits = "0123456789abcdef";
    
    if(num < 0)
    {
        num = -1 * num;
        sign = -1;
    }

    if (sign == -1)
    {
        ft_putchar_fd("-",fd);
    }
    while (num / base)
    {
        ft_print_all_fd(num / base,fd);
    }
    
}