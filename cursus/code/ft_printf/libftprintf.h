#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "/Users/jason/Developer/42/cursus/code/libft.a/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_arg
{
    int len;
    int dot;
    int space;
    int zero;
    int upper;
    int hash;
    int minus;
    int plus;
    int precision;
    int width;
    int zpad;
    int spad;
    va_list ap;
} t_arg;

# define FD 1;

//ft_printf.c
int ft_printf(const char *string, ...);
char *ft_main_process(char *str, t_arg *arg);
void ft_flag_process(char c, t_arg *arg);

//ft_subft.c
void ft_arg_init(t_arg *arg);
int ft_allnblen(long long num,int base);
int ft_unsigned_allnblen(long long num,int base);
void ft_putunbr_base_fd(long long num,int base,int fd);
void ft_putsnbr_base_fd(t_arg *arg,long long num,int base,int fd);

//ft_printf_utils.c
void ft_print_char(t_arg *arg);
void ft_print_str(t_arg *arg);
void ft_print_ptr(t_arg *arg);
void ft_print_int(t_arg *arg);
void ft_print_uint(t_arg *arg,char c,int base);
#endif