#include "../headers/ft_printf.h"

static int	ft_check_minus_first(char *format,
			t_format *print_format, int *offset)
{
	if (*format == '-')
	{
		while (*format == '-')
		{
			print_format->flags.minus = 1;
			(*offset)++;
			format++;
		}
		if (ft_is_allowed_char(*format))
		{
			while (*format == '0')
			{
				print_format->flags.zero = 1;
				(*offset)++;
				format++;
			}
		}
		else
			return (-1);
	}
	return (0);
}

static int	ft_check_zero_first(char *format,
			t_format *print_format, int *offset)
{
	if (*format == '0')
	{
		while (*format == '0')
		{
			print_format->flags.zero = 1;
			(*offset)++;
			format++;
		}
		if (ft_is_allowed_char(*format))
		{
			while (*format == '-')
			{
				print_format->flags.minus = 1;
				(*offset)++;
				format++;
			}
		}
		else
			return (-1);
	}
	return (0);
}

static int	ft_skip_spaces(char **format)
{
	int	count;

	if (!format || !*format)
		return (0);
	count = 0;
	while (**format == ' ')
	{
		ft_putchar(' ');
		(*format)++;
		count++;
	}
	return (count);
}

int	ft_fill_flags(char *format, t_format *print_format, int *offset)
{
	if (!format || !print_format || !offset)
		return (-1);
	*offset += ft_skip_spaces(&format);
	if (ft_is_allowed_char(*format))
	{
		if (ft_check_minus_first(format, print_format, offset) == -1)
			return (-1);
		else if (ft_check_zero_first(format, print_format, offset) == -1)
			return (-1);
	}
	else
		return (-1);
	return (0);
}
