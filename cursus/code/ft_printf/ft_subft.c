#include "libftprintf.h"

void	ft_arg_init(t_arg *arg)
{
	arg->dot = 0;
	arg->hash = 0;
	arg->upper = 0;
	arg->minus = 0;
	arg->plus = 0;
	arg->space = 0;
	arg->zero = 0;
	arg->precision = 0;
	arg->width = 0;
	arg->spad = 0;
	arg->zpad = 0;
}

int	ft_allnblen(long long num, int base)
{
	if (num < 0)
	{
		num = -1 * num;
		return (1 + ft_allnblen(num / base, base));
	}
	if ((num / base) == 0)
	{
		return (1);
	}
	return (1 + ft_allnblen(num / base, base)); // why (num/base) get err
}

int	ft_unsign_allnblen(long long num, int base)
{
	if (num < 0)
	{
		num = -1 * num;
		return (ft_allnblen(num / base, base));
	}
	return (ft_allnblen(num / base, base));
}

void	ft_putunbr_base_fd(long long num, int base, int fd)
{
	char	*digit;

	digit = "0123456789abcdef";
	if (num / base)
		ft_putunbr_base_fd(num / base, base, fd);
	ft_putchar_fd(digit[num % base], fd);
}
void	reset(t_arg *arg)
{
	arg->hash = 0;
	arg->plus = 0;
	arg->space = 0;
}
void	ft_putsnbr_base_fd(t_arg *arg, long long num, int base, int fd)
{
	char *digit;

	digit = "0123456789abcdef";

	if (num < 0)
	{
		num = -1 * num;
		ft_putchar_fd('-', FD);
	}
	else if (arg->hash && arg->upper)
	{
		ft_putstr_fd("0X", FD);
	}
	else if (arg->hash && !arg->upper)
	{
		ft_putstr_fd("0x", FD);
	}
	else if (arg->plus)
	{
		ft_putchar_fd('+', FD);
	}
	else if (arg->space)
	{
		ft_putchar_fd(' ', FD);
	}
	if (arg->upper)
	{
		digit = "0123456789ABCDEF";
	}
	while (arg->zpad)
	{
		ft_putchar_fd('0', FD);
		arg->zpad--;
	}
	reset(arg);
	if (num / base)
		ft_putunbr_base_fd(num / base, base, fd);
	ft_putchar_fd(digit[num % base], fd);
}