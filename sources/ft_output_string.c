#include "../headers/ft_printf.h"

int	ft_output_string(t_format *print_format, char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		str = "";
		if (print_format->precision < 0 || print_format->precision >= 6)
			str = "(null)";
	}
	if (print_format->precision == -1)
		print_format->precision = ft_strlen(str);
	if (print_format->flags.minus == 1)
	{
		print_format->flags.zero = 0;
		count += ft_putstr(str, print_format->precision);
		count += ft_output_spaces(print_format->width - count);
	}
	else
	{
		count += ft_output_spaces(print_format->width
				- ft_min(ft_strlen(str), print_format->precision));
		count += ft_putstr(str,
				ft_min(ft_strlen(str), print_format->precision));
	}
	return (count);
}
