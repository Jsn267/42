#include "libftprintf.h"

void    ft_print_char(t_arg *arg)
{
    const char c    =   va_arg(arg->ap,char);

    if (arg->width > arg->precision)
        arg->spad = arg->width - arg->precision - 1;//1 for char
    
    arg->len += arg->spad + 1;

    if (arg->minus)
    {
        ft_putchar_fd(c,1);//why cannt put FD
        while (arg->spad--)
            ft_putchar_fd(' ',1);
    }
    else
    {
       while (arg->spad--)
            ft_putchar_fd(' ',1); 
       ft_putchar_fd(c,1);
    }
}

void    ft_print_str(t_arg *arg)
{
    int str_len;

    const char *str = va_arg(arg->ap,char *);

    if (!str)
        str = "(null)";
    
    str_len = ft_strlen(str);
    
   if (arg->precision > str_len)
        arg->precision = str_len;
   if (arg->width > arg->precision)
        arg->spad = arg->width - arg->precision;
   arg->len += arg->spad + arg->precision;
    if (arg->minus)
    {
        ft_putstr_fd(str,1);
        while (arg->spad--)
            ft_putchar_fd(' ',1);
    }
    else
    {
       while (arg->spad--)
            ft_putchar_fd(' ',1);
        write(1,str,arg->precision);
    }
}

void    ft_print_ptr(t_arg *arg)
{
    int len;

    const long long n = va_arg(arg->ap,long long);
    len = ft_allnblen(n,16) + 2;

    if (arg->width > len)
        arg->spad = arg->width - len;
    arg->len = arg->spad + len;

    if (arg->minus)
    {
        ft_putstr_fd("x0",1);
        ft_putunbr_base_fd(n,16,1);
        while (arg->spad--)
            ft_putchar_fd(' ',1);
    }
    else
    {
        while (arg->spad--)
            ft_putchar_fd(' ',1);
        ft_putstr_fd("x0",1);
        ft_putunbr_base_fd(n,16,1); 
    }
}

void ft_print_int(t_arg *arg)
{
    int len;

    const int n = va_arg(arg->ap,int);
    
    if (arg->dot || arg->zero)
    {
        len = ft_unsigned_allnblen(n,10);
    }
    else
    {
        len = ft_allnblen(n,10);
    }
    if (arg->width > len)//%_ni,%ni,%+5i
        arg->loop = arg->width - len;
    if (arg->precision)
    {
        arg->loop = arg->precision - len;
        if (arg->zero && n < 0)
            arg->loop = arg->loop - 1;//-1 for sign %05i>> -0042
        arg->padding = '0';
    }
    arg->len = arg->loop + len;
    
    if (arg->minus)
    {
        if (arg->plus && n > -1)
        {
            ft_putchar_fd('+',1);
            arg->loop = arg->loop - 1;
        }
        ft_putunbr_base_fd(n,10,1);//not using putnbr bcz of sign
        while (arg->loop)
            ft_putchar_fd(arg->padding,1);
    }
    else
    {
        if ((arg->dot || arg->zero) && n < 0)
            ft_putchar_fd('-',1);
        if (arg->dot && arg->plus)
            ft_putchar_fd('+',1);
        while (arg->loop)
            ft_putchar_fd(arg->padding,1);
        if ((arg->dot || arg->zero) && n < 0)
        {
            ft_putnbr_fd(-(n),1);
        }
        else
            ft_putnbr_fd(n,1);        
    }
}

void ft_print_uint(t_arg *arg,char c,int base)
{
    int len;

    const int n = va_arg(arg->ap,unsigned int);
    len = ft_unsigned_allnblen(n,base);

    if (c == "X")
        arg->upper = 1;
    if (arg->hash && n > 0)
		arg->len += 2;
	if (arg->precision > len)
		arg->zpad = arg->precision - len;    
	if (arg->width > len)
		arg->spad = arg->width - len;
	arg->len += arg->spad + arg->zpad + len;

    if (arg->minus)
    {
        ft_putsnbr_base_fd(arg,n,base,1);
        while (arg->spad)
            ft_putchar_fd(' ',1);
    }
    else 
    {
        while (arg->spad)
            ft_putchar_fd(' ',1);
        ft_putsnbr_base_fd(arg,n,base,1);
    }
}