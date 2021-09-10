#include "../headers/ft_printf.h"

static int	ft_output_decimal_and_zeros(t_format *print_format, long long *a)
{
	int	count;
	int	is_negative;

	count = 0;
	is_negative = 0;
	if (*a < 0)
	{
		count += ft_putchar('-');
		is_negative = 1;
	}
	if (is_negative)
	{
		*a = -(*a);
		count += ft_output_zeros(print_format->width - 1
				- ft_max(ft_numberlen(*a), print_format->precision));
	}
	else
		count += ft_output_zeros(print_format->width
				- ft_max(ft_numberlen(*a), print_format->precision));
	return (count);
}

static int	ft_output_decimal_and_spaces(t_format *print_format, long long *a)
{
	int	count;
	int	is_negative;

	count = 0;
	is_negative = 0;
	if (*a < 0)
		is_negative = 1;
	if (is_negative)
	{
		*a = -(*a);
		count += ft_output_spaces(print_format->width - 1
				- ft_max(ft_numberlen(*a), print_format->precision));
	}
	else if (*a == 0 && print_format->precision == 0)
		count += ft_output_spaces(print_format->width);
	else
	{
		count += ft_output_spaces(print_format->width
				- ft_max(ft_numberlen(*a), print_format->precision));
	}
	if (is_negative)
		ft_putchar('-');
	return (count);
}

int	ft_output_decimal(t_format *print_format, long long a)
{
	int	count;

	count = 0;
	if (print_format->flags.minus == 1)
	{
		count += ft_putnbr_decimal(&a, print_format->precision);
		if (print_format->width > 0)
			count += ft_output_spaces(print_format->width - count);
	}
	else
	{
		if (print_format->width > 0)
		{
			if (print_format->precision != -1)
				print_format->flags.zero = 0;
			if (print_format->flags.zero == 1)
				count = ft_output_decimal_and_zeros(print_format, &a);
			else
				count = ft_output_decimal_and_spaces(print_format, &a);
		}
		count += ft_putnbr_decimal(&a, print_format->precision);
	}
	return (count);
}
