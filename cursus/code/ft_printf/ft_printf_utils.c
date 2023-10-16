#include "libftprintf.h"

void ft_print_char(t_args *args)
{
    char c;

    c = va_arg(args->ap,char);

    if (args->width > args->precision)
    {
            args->pspace = args->width - 1;
    }
    // c = a;
    // %3c = __a;

    args->len += args->pspace + 1;
    if (args->minus = 1)
    {
        ft_putchar_fd(c,1);
        while(args->pspace != 0)
        {
            ft_putchar_fd(' ',1);
            args->pspace--;
        }
    }
    else
    {
         while(args->pspace != 0)
        {
            ft_putchar_fd(' ',1);
            args->pspace--;
        } 
        ft_putchar_fd(c,1);   
    }
}

void    ft_print_str(t_args *args)
{
    int len;
    char *str;
    
    len = ft_strlen(str);
    str = va_arg(args->ap,char *);
    
    if(!str)
        str = '\0';

    if (!args->dot || args->precision)    
        args->precision = len;
    if (args->width > args->precision)
        args->pspace = args->width - args->precision;

    //str = abc;
    //%5s = __abc; (5-len(str))
    
    args->len += args->pspace + args->precision;
    if (args->minus)
	{
		ft_putstr_fd((char *)str, 1);
		while (args->pspace--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (args->pspace--)
			ft_putchar_fd(' ', 1);
		write((char *)str, args->precision, 1);//recheck
	}
}

void ft_print_ptr(t_args *args)
{
    long long num;
    char *hex;
    int len;

    num = va_arg(args->ap,long long) + ULONG_MAX + 1;
    len = ft_allintlen(num,16) + 2;//2 for x0

    if (args->width > len)
    {
        args->pspace = args->width - len;
    }    
    if (args->minus)
    {
        ft_putstr_fd("0x",1);
        ft_puthex_fd(num,1);
        while (args->pspace--)
            ft_putchar_fd(' ',1);
    }
    else 
    {
        while (args->pspace--)
            ft_putchar_fd(' ',1);
        ft_putstr_fd("0x",1);
        ft_puthex_fd(num,1); 
    }
}

void ft_print_int(t_args *args)
{
    int num;
    int len;

    num = va_arg(args->ap,int);
    len = ft_allintlen(num,10);

    if (args->precision > len)
    {
        args->pzero = args->precision - len;
    }
   
    if (args->width > len)
    {
        args->pspace = args->width - len;
    }

    if (args->plus)
    {
        if(num > -1)
        {
            if(args->precision)
            {
                args->precision - 1;//for plus sign
            }
            if (args->width)
            {
                args->width - 1;
            }
        }
    }
    while (args->width || args->precision)
    {
        if(args->minus)
        {
            while (args->width){}
        }
        else
        {
           if(args->width || args->space)// %5i,%+5i,% 5i >>>__-42
           {
            while (args->pspace)
            {
                ft_putchar_fd(' ',FD);
                args->pspace--;
            }
            if(args->plus)//__+42
                ft_putchar_fd('+',FD);
            ft_putnbr_fd(num,FD);
           }
           if(args->zero || args->dot)//%.5i %+.5i %05i >>> -0042
           {
            if(num < 0)
            {
                ft_putchar_fd('-',FD);
                if(args->dot)//.5i>>>-00042
                    args->pzero + 1;
                while(args->pzero)
                {
                    ft_putnbr_fd(0,FD);
                }
                ft_putnbr_fd(-(num),FD);
            }
            else
            {
                if(args->plus)//+0042
                    ft_putchar_fd('+',FD);
                if(args->dot)//+00042
                    args->pzero + 1;
               while(args->pzero)//00042
                {
                    ft_putnbr_fd(0,FD);
                }
                ft_putnbr_fd(num,FD); 
            }
           }
        }
    }
}