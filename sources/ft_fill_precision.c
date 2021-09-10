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

int	ft_fill_precision(char *format, va_list *argc,
		t_format *print_format, int *offset)
{
	int	precision;

	if (!format || !argc || !print_format)
		return (-1);
	if (*format == '.')
	{
		format++;
		(*offset)++;
		precision = 0;
		if (*format == '*')
		{
			precision = va_arg(*argc, int);
			format++;
			(*offset)++;
		}
		else if (ft_isdigit(*format))
		{
			*offset += ft_get_minus_count(&format);
			precision = ft_atoi(format);
			*offset += ft_skip_digits(&format);
		}
		if (precision > -1)
			print_format->precision = precision;
	}
	return (0);
}
