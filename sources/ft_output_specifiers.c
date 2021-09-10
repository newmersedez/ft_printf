#include "../headers/ft_printf.h"

int	ft_output_specifiers(va_list *argc, t_format *print_format)
{
	int	count;

	if (!argc || !print_format)
		return (-1);
	if (print_format->type == '%')
		count = ft_output_percent();
	if (print_format->type == 'c')
		count = ft_output_char(print_format, (char)va_arg(*argc, int));
	if (print_format->type == 's')
		count = ft_output_string(print_format, va_arg(*argc, char *));
	if (print_format->type == 'p')
		count = ft_output_address(print_format, va_arg(*argc, void *));
	if (print_format->type == 'd' || print_format->type == 'i')
		count = ft_output_decimal(print_format, va_arg(*argc, int));
	if (print_format->type == 'u')
		count = ft_output_decimal(print_format, va_arg(*argc, unsigned int));
	if (print_format->type == 'x')
		count = ft_output_hexadecimal_lowercase(print_format,
				va_arg(*argc, unsigned int));
	if (print_format->type == 'X')
		count = ft_output_hexadecimal_uppercase(print_format,
				va_arg(*argc, unsigned int));
	return (count);
}
