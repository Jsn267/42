#include "libftprintf.h"

void	ft_printf_char(t_arg *arg)
{
	char	c;

	c = va_arg(arg->ap, int);
	if (arg->width > arg->precision)
		arg->spad = arg->width - arg->precision - 1; // 1 for char
	arg->len += arg->spad + 1;
	if (arg->minus)
	{
		ft_putchar_fd(c, FD); // why cannt put FD
		while (arg->spad--)
			ft_putchar_fd(' ', FD);
	}
	else
	{
		while (arg->spad--)
			ft_putchar_fd(' ', FD);
		ft_putchar_fd(c, FD);
	}
}

void	ft_printf_str(t_arg *arg)
{
	int		str_len;
	char	*str;

	str = va_arg(arg->ap, char *);
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
		ft_putstr_fd(str, FD);
		while (arg->spad--)
			ft_putchar_fd(' ', FD);
	}
	else
	{
		while (arg->spad--)
			ft_putchar_fd(' ', FD);
		write(FD, str, arg->precision);
	}
}

void	ft_printf_ptr(t_arg *arg)
{
	int			len;
	long long	n;

	n = va_arg(arg->ap, int);
	len = ft_allnblen(n, 16) + 2;
	if (arg->width > len)
		arg->spad = arg->width - len;
	arg->len += arg->spad + len;
	if (arg->minus)
	{
		ft_putstr_fd("x0", FD);
		ft_putunbr_base_fd(n, 16, FD);
		while (arg->spad--)
			ft_putchar_fd(' ', FD);
	}
	else
	{
		while (arg->spad--)
			ft_putchar_fd(' ', FD);
		ft_putstr_fd("x0", FD);
		ft_putunbr_base_fd(n, 16, FD);
	}
}

void	ft_printf_int(t_arg *arg)
{
	int	len;
	int	unsigned_len;
	int	n;

	n = va_arg(arg->ap, int);
	len = ft_allnblen(n, 10);
	unsigned_len = ft_unsigned_allnblen(n, 10);
	if (arg->precision > unsigned_len)
		arg->zpad = arg->precision - unsigned_len;
	if (arg->zero && n < 0 && arg->zpad) // %05i >>> -0042
		arg->zpad--;
	if (arg->width > arg->zpad + len)
		arg->spad = arg->width - arg->zpad - len;
	if ((arg->space || arg->plus) && n >= 0 && arg->spad)
	{
		arg->spad--;
		arg->len++;
	}
	arg->len += arg->spad + arg->zpad + len;
	if (arg->minus)
	{
		ft_putsnbr_base_fd(arg, n, 10, FD);
		while (arg->spad--)
			ft_putchar_fd(' ', FD);
	}
	else
	{
		while (arg->spad--)
			ft_putchar_fd(' ', FD);
		ft_putsnbr_base_fd(arg, n, 10, FD);
	}
}

void	ft_printf_uint(t_arg *arg, char c, int base)
{
	int len;

	int n = va_arg(arg->ap, unsigned int);
	len = ft_unsigned_allnblen(n, base);

	if (c == 'X')
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
		ft_putsnbr_base_fd(arg, n, base, FD);
		while (arg->spad)
			ft_putchar_fd(' ', FD);
	}
	else
	{
		while (arg->spad)
			ft_putchar_fd(' ', FD);
		ft_putsnbr_base_fd(arg, n, base, FD);
	}
}