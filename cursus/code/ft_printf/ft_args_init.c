#include "libftprintf.h"

void ft_args_init(t_args *args)
{
    args->blank = 0;
    args->dash = 0;
    args->hash = 0;
    args->minus = 0;
    args->plus = 0;
    args->space = 0;
    args->dot = 0;
    args->pspace = 0;
    args->pzero = 0;
    args->zero = 0;
}