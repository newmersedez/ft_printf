#include "../headers/ft_printf.h"

int	ft_output_char(t_format *print_format, char c)
{
	int	count;

	count = 0;
	if (print_format->precision != 0)
		print_format->precision = 0;
	if (print_format->flags.zero == 1)
		print_format->flags.zero = 0;
	if (print_format->flags.minus == 1)
	{
		print_format->flags.zero = 0;
		count += ft_putchar(c);
		if (print_format->width > 0)
			count += ft_output_spaces(print_format->width - 1);
	}
	else
	{
		if (print_format->width > 0)
			count += ft_output_spaces(print_format->width - 1);
		count += ft_putchar(c);
	}
	return (count);
}
