#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "./libft.a/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
typedef struct s_args
{
    va_list ap;
    int space;
    int hash;
    int zero;
    int dash;
    int minus;
    int plus;
    int dot;
    int precision;
    int blank;
    int	len;
	int	pspace;
	int	pzero;
	int	width;
	int	upper;
	
} t_args;

# define FD 1 //1 represent standart output

int ft_printf(const char *format, ...);
int ft_print_on_screen(const char *format ,t_args *args);
char *ft_main_process(char *str, t_args *args);
void ft_flag_process(char c,t_args *args);
void ft_args_init(t_args *args);

//ft_print_utils
void ft_print_char(t_args *args);
void    ft_print_str(t_args *args);
void ft_print_ptr(t_args *args);
void ft_print_int(t_args *args);

//ft_hax_utils
int ft_allintlen(long long num,int base);
void ft_puthex_fd(long long num,int fd);
void ft_print_all_nbr(t_args *args,long long num ,int base, int fd);

#endif