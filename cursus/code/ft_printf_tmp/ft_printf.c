#include "libftprintf.h"

int ft_printf(const char *str, ...)
{
    int word_len;
    t_args args;

    ft_args_init(&args);
    args.len = 0;

    va_start(args.ap,str);
    word_len = ft_print_on_screen(str,&args);
    va_end(args.ap);
    return (word_len);
}

int main(void)
{
    int i = 42;
    
}