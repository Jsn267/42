#include "libftprintf.h"

int ft_printf(const char *string, ...)
{
    int word_len;
    t_arg arg;

    ft_arg_init(&arg);
    arg.len = 0;

    va_start(arg.ap,string);
    
    while (*string)
    {
        if (*string == "%")
        {
            string = ft_main_process((char *)string,&arg);
            ft_arg_init(&arg);
        }
        else
        {
            word_len++;
            ft_putchar_fd(*string,1);
        }
    }

    va_end(arg.ap);
    return (word_len+arg.len);
}

char *ft_main_process(char *str, t_arg *arg)
{
    while (*str && !ft_strchr("cspdiuxX%",*str))
    {
        ft_flag_process(*str,arg);
        str++;
    }
    if (*str == 'c')
		ft_printf_char(arg);
	else if (*str == 's')
		ft_printf_str(arg);
	else if (*str == 'p')
		ft_printf_ptr(arg);
	else if (*str == 'd' || *str == 'i')
		ft_printf_int(arg);
	else if (*str == 'u')
		ft_printf_uint(*str, 10, arg);
	else if (*str == 'x' || *str == 'X')
		ft_printf_uint(*str, 16, arg);
	else if (*str == '%' && ++arg->len)
		ft_putchar_fd(*str, 1);
    str++;
	return (str);
}

void ft_flag_process(char c,t_arg *arg)
{
    if (ft_isdigit(c))
    {
        if (arg->dot || arg->zero)
        {
            arg->precision = (arg->precision * 10 + c - '0');
        }
        else 
        {
            if (arg->width == 0 && c == '0')
            {
                arg->zero = 1;
            }
            else
                arg->width = (arg->width * 10 + c - '0');
        }
    }
    else if (c == '#')
		arg->hash = 1;
	else if (c == '-')
		arg->minus = 1;
	else if (c == ' ')
		arg->space = 1;
	else if (c == '+')
		arg->plus = 1;
	else if (c == '.')
		arg->dot = 1;
}