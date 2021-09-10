#include "../headers/ft_printf.h"

static int	ft_output_zeros_or_spaces(t_format *print_format, long long a)
{
	int	count;
	int	numlen;

	count = 0;
	numlen = ft_hexnumberlen(a);
	if (a == 0 && print_format->precision == 0)
		numlen = 0;
	if (print_format->flags.zero == 1)
		count += ft_output_zeros(print_format->width
				- ft_max(numlen, print_format->precision));
	else
		count += ft_output_spaces(print_format->width
				- ft_max(numlen, print_format->precision));
	return (count);
}

int	ft_output_hexadecimal_lowercase(t_format *print_format,
		unsigned long long a)
{
	int	count;

	count = 0;
	if (print_format->flags.minus == 1)
	{
		count += ft_putnbr_hex_lowercase(a, print_format->precision);
		if (print_format->width > 0)
			count += ft_output_spaces(print_format->width - count);
	}
	else
	{
		if (print_format->width > 0)
		{
			if (print_format->precision != -1)
				print_format->flags.zero = 0;
			count += ft_output_zeros_or_spaces(print_format, a);
		}
		count += ft_putnbr_hex_lowercase(a, print_format->precision);
	}
	return (count);
}

int	ft_output_hexadecimal_uppercase(t_format *print_format,
		unsigned long long a)
{
	int	count;

	count = 0;
	if (print_format->flags.minus == 1)
	{
		count += ft_putnbr_hex_uppercase(a, print_format->precision);
		if (print_format->width > 0)
			count += ft_output_spaces(print_format->width - count);
	}
	else
	{
		if (print_format->width > 0)
		{
			if (print_format->precision != -1)
				print_format->flags.zero = 0;
			count += ft_output_zeros_or_spaces(print_format, a);
		}
		count += ft_putnbr_hex_uppercase(a, print_format->precision);
	}
	return (count);
}
