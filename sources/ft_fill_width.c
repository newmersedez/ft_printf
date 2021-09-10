#include "../headers/ft_printf.h"

static int	ft_get_minus_count(char **format)
{
	int	count;

	if (!format || !*format)
		return (0);
	count = 0;
	while (**format == '-')
	{
		(*format)++;
		count++;
	}
	return (count);
}

static int	ft_skip_digits(char **format)
{
	int	count;

	if (!format || !*format)
		return (0);
	count = 0;
	while (ft_isdigit(**format))
	{
		(*format)++;
		count++;
	}
	return (count);
}

static int	ft_skip_spaces(char **format)
{
	int	count;

	if (!format || !*format)
		return (0);
	count = 0;
	while (**format == ' ')
	{
		(*format)++;
		count++;
	}
	return (count);
}

int	ft_fill_width(char *format, va_list *argc,
		t_format *print_format, int *offset)
{
	int	width;

	if (!format || !argc || !print_format)
		return (-1);
	width = 0;
	*offset += ft_skip_spaces(&format);
	if (*format == '*')
	{
		width = va_arg(*argc, int);
		if (print_format->flags.minus == 0 && width < 0)
			print_format->flags.minus = 1;
		(*offset)++;
		format++;
	}
	else if (ft_isdigit(*format))
	{
		*offset += ft_get_minus_count(&format);
		width = ft_atoi(format);
		*offset += ft_skip_digits(&format);
	}
	if (width < 0)
		print_format->width = -width;
	else
		print_format->width = width;
	return (0);
}
