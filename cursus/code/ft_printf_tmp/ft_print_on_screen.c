#include "libftprintf.h"

int ft_print_on_screen(const char *string,t_args *args)
{
    while (*string)
    {
        if (*string == "%")
        {
            ft_main_process(string,args);
            ft_args_init(&args);
        }
        else 
            ft_putchar_fd(*string,1);
        
        string++;
    }
    return (args->len);
}

char *ft_main_process(char *str, t_args *args)
{
    while (*str && !ft_strchr("cspdiuxX%",*str))
    {
        ft_flag_process(*str,args);
        str++;
    }
    if (*str == 'c')
		ft_printf_char(args);
	else if (*str == 's')
		ft_printf_str(args);
	else if (*str == 'p')
		ft_printf_ptr(args);
	else if (*str == 'd' || *str == 'i')
		ft_printf_int(args);
	else if (*str == 'u')
		ft_printf_uint(*str, 10, args);
	else if (*str == 'x' || *str == 'X')
		ft_printf_uint(*str, 16, args);
	else if (*str == '%' && ++args->len)
		ft_putchar_fd(*str, 1);
    str++;
	return (str);
}

void ft_flag_process(char c,t_args *args)
{
    if (ft_isdigit(c))
    {
        if (args->dot || args->zero)
        {
            args->precision = (args->precision * 10 + c - '0');
        }
        else 
        {
            if (args->width == 0 && c == '0')
            {
                args->zero = 1;
            }
            else
                args->width = (args->width * 10 + c - '0');
        }
    }
    else if (c == '#')
		args->hash = 1;
	else if (c == '-')
		args->minus = 1;
	else if (c == ' ')
		args->space = 1;
	else if (c == '+')
		args->plus = 1;
	else if (c == '.')
		args->dot = 1;
}